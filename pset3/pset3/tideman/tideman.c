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
void print_preferences_matrix(void);

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

        // Function call
        record_preferences(ranks);
        printf("\n");
        print_preferences_matrix();
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
// The ranks[] array holds the ranks of the candidates for a single voter's ballot
bool vote(int rank, string name, int ranks[])
{
printf("\n");
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
        for (int i = 0; i < candidate_count; i++)
{
    printf("%d ", ranks[i]);
}
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
// The record_preferences function knows where to increment based on the ranks array. The ranks array represents the order of candidates as ranked by a voter.
// The index in the ranks array represents the rank and the value at that index represents the candidate.
// There's no need for an if statement here because the loops are already set up to only compare each candidate (represented by row) with the candidates ranked lower than them (represented by column).
// This 2d Array now contains all of the data we need about individual voter preferences to "pair" the candidates of each pair of the election

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
        printf("\n");
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
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
