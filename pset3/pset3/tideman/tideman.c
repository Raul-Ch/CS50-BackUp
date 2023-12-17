#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

// Debug
void print_preferences(int ranks[]);
void print_preferences_matrix(void);
void print_pairs(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    // Prompt to input the number of votes
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference  This array will hold the voter's ranking of the candidates
        // Each index i in the ranks array will hold the index of the candidate that the voter has ranked in the ith position
        int ranks[candidate_count];

        // Query for each rank
        // Iterate over each candidate. The variable j represents the current candidate's rank.
        for (int j = 0; j < candidate_count; j++)
        {
            // Prompt to input the name of the candidate
            string name = get_string("Rank %i: ", j + 1);

            //  Call that attempts to record a vote for the candidate name at rank j.
            if (!vote(j, name, ranks))
            {
                // If returns false the vote is invalid
                printf("Invalid vote.\n");
                return 3;
            }
        }
        printf("\n");
        // Function call
        record_preferences(ranks);
        // print_preferences();
        // print_preferences_matrix();
    }

    add_pairs();
    print_preferences_matrix();
    // print_pairs();
    sort_pairs();
    print_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
// The ranks[] array holds the ranks of the candidates for a single voter's ballot
bool vote(int rank, string name, int ranks[])
{
    // TODO
    // Check if the name is a match for the name of a valid candidate
    // The function iterates over all candidates.
    for (int i = 0; i < candidate_count; i++)
    {
        //  If it finds a candidate whose name matches the input name
        if (strcmp(name, candidates[i]) == 0)
        {
            // Save the place of the candidate[] in order of preference
            ranks[rank] = i;
            return true;
        }
    }
    // Else Flase
    return false;
}

// Update preferences given one voter's ranks
// 2D array, preferences [i][j] is number of voters who prefer candidate i over candidate j
void record_preferences(int ranks[])
{
    // TODO
    // Record over how many candidates are below
    // Iterate over each candidate.
    for (int row = 0; row < candidate_count; row++)
    {
        // It iterates over all candidates that are ranked lower than the current candidate in the ballot.
        for (int column = row + 1; column < candidate_count; column++)
        {
            //  this line increments the count of preferences for each candidate over the candidates ranked lower than them.
            preferences[ranks[row]][ranks[column]]++;
            // "increase the preference count for the candidate at ranks[row] over the candidate at ranks[column]".
        }
    }
    return;
}
// The record_preferences function knows where to increment based on the ranks array. The ranks array represents the order of
// candidates as ranked by a voter. The index in the ranks array represents the rank and the value at that index represents the
// candidate. There's no need for an if statement here because the loops are already set up to only compare each candidate
// (represented by row) with the candidates ranked lower than them (represented by column). This 2d Array now contains all of the
// data we need about individual voter preferences to "pair" the candidates of each pair of the election

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Initialize pair count to 0
    pair_count = 0;
    // TODO
    //  i for and j for: Iterate over all pairs of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            //  If candidate i is preferred over candidate j (Matrix of row = i and columns = j)
            if (preferences[i][j] > preferences[j][i])
            {
                // Candidate i (column) as the winner
                pairs[pair_count].winner = i;
                // Candidate j (row) as the loser
                pairs[pair_count].loser = j;
                // Pair count
                pair_count++;
            }
            //  Else If candidate j is preferred over candidate i (Matrix of row = i and jcolumns = j)
            else if (preferences[i][j] < preferences[j][i])
            {
                // Set candidate j as the winner
                pairs[pair_count].winner = j;
                // Set candidate i as the loser
                pairs[pair_count].loser = i;
                // Pair count
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
// The strength of victory is defined as the number of voters who prefer the preferred candidate.
void sort_pairs(void)
{
    // TODO - expected to implement a sorting algorithm: Buuble Sort
    // Loop over each pair in the array
    for (int i = 0; i < pair_count - 1; i++)
    {
        // For each pair, compare it with the next pair
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            // Calculate the margin of victory for the current pair
            int margin_current = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            // Calculate the margin of victory for the next pair
            int margin_next = preferences[pairs[j + 1].winner][pairs[j + 1].loser] - preferences[pairs[j + 1].loser][pairs[j + 1].winner];

            // Swap pairs if the strength of victory is less in the current pair
            if (margin_current < margin_next)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {

        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

// Print Prefeerences:
void print_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        printf("%d ", ranks[i]);
    }
}

// Print the preferences matrix
void print_preferences_matrix(void)
{
    printf("Preferences Matrix:\n");

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%2d ", preferences[i][j]);
        }
        printf("\n");
    }
}

// Print the preferences matrix
void print_pairs(void)
{
    printf("Pairs:\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("Pair %d: Winner = %s, Loser = %s\n", i, candidates[pairs[i].winner], candidates[pairs[i].loser]);
    }
}
