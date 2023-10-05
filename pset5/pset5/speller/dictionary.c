// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

int size_counter = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
// size of words
const unsigned int N = 70;
const unsigned int N2 = 26;

// Hash table
node *table[N];
node *table2[N2];

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char buffer[N];
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
            // Create a new node for each word
            node *l_node = malloc(sizeof(node));
            if (l_node == NULL)
            {
                printf("No space");
                return false;
            }
            else
            {
                size_counter++;.
                // Hash a word to obtain a hash value
                // Copy word into node using strcpy
                strcpy(l_node -> word, buffer);
                l_node -> next = NULL;
                // Use hash function (takes a string and returns an index)
                // Recall that hash table is an array
                int length = hash(l_node -> word);
                // If array is empty
                if (table[length] == NULL)
                {
                    // This node is the whole list
                    table[length] = l_node;
                }
                 // If array has numbers already
                else
                {
                    // Insert node at beginning of list
                    l_node -> next = table[length];
                    table[length] = l_node;
                }
            }
        }
    }
    // Insert node into hash table at that location
    fclose(file);
    return true;
}


// Hashes word to a number (by length)
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int atoz = toupper(word[0]) - 'A';
    unsigned int length = strlen(word);
    // the bucket can go from 1 (min letter = a + 1 of lenght)
    // to 25 + 45 (25 being 'Z' and 45 the max length)
    return atoz + length;
}

// Hashes word to a number (By A - Z)
unsigned int hash2(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return  size_counter;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash word to obtain a hash value
    // Access linked list at that index in the hash table
    table[hash(word)];
    // Traverse linked list, looking for the word (strcasecmp)
    cursor = cursor -> next;
    return false;
}


// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
