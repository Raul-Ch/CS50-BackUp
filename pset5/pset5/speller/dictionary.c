// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
// size of words
const unsigned int N = 45;
const unsigned int N2 = 26;

// Hash table
node *table[N];
node *table2[N2];

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char buffer[45];
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Return value NULL");
        return false;
    }
    else
    {
        // Check if fscanf returns 1, which indicates it successfully read a string.
        // Read strings from file one at a time
        while (fscanf(file, "%s", buffer) == 1)
        {
            node *l_node = malloc(sizeof(node));
            if (l_node == NULL)
            {
                printf("No space");
                return false;
            }
            else
            {
                 int length = malloc(sizeof(int));
                 length = strlen(buffer) + 1;
    printf("%i", length);

                 //char *tmp_len = s;
            }
        }
    }

    // Create a new node for each word

    // Hash a word to obtain a hash value

    // Insert node into hash table at that location
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
