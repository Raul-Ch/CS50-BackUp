// Saves popular dog names in a trie
// https://www.dailypaws.com/dogs-puppies/dog-names/common-dog-names

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26
#define MAXCHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
} node;

// Function prototypes
bool check(char *word);
bool unload(void);
void unloader(node *current);

// Root of trie
node *root;

// Buffer to read dog names into
char name[MAXCHAR];

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate root of trie
    root = malloc(sizeof(node));

    if (root == NULL)
    {
        return 1;
    }

    root->is_word = false;
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        root->children[i] = NULL;
    }

    // Add words to the trie
    while (fscanf(infile, "%s", name) == 1)
    {
        node *cursor = root;

        for (int i = 0, n = strlen(name); i < n; i++)
        {
            int index = tolower(name[i]) - 'a';
            if (cursor->children[index] == NULL)
            {

                // Make node
                node *new = malloc(sizeof(node));
                new->is_word = false;
                for (int j = 0; j < SIZE_OF_ALPHABET; j++)
                {
                    new->children[j] = NULL;
                }
                cursor->children[index] = new;
            }

            // Go to node which we may have just been made
            cursor = cursor->children[index];
        }

        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }

    if (check(get_string("Check word: ")))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(infile);
}

// TODO: Complete the check function, return true if found, false if not found
bool check(char *word)
{
    // HERE we check:
    // Verificamos por cada letra, si esta existe o no en el trie al cual nos referimos segun el Num de index dependiendod de la iteración en la que nos encontramos
    // Al final, si se encuentran "todas las letras" de la palabra dada, llegaremos al puntero con el valor is_word: verdadero, si no encontramos este valor o una letra
    // al final de la "cadena" entonces no existe la palabra

    // Setting a node pointer to navigate, cursor to the root of the trie.
    node *cursor = root;

    // Iterate through every letter in the argument WORD (given by the user) and, as you do,
    for (int i = 0, letter = strlen(word); i < letter; i++)
    {
        // determine the array index that corresponds to that letter.
        int index = toupper(word[i]) - 'A';

        // Check if there´s an error on the word given (character evaluated)
        if (index < 0 || index >= SIZE_OF_ALPHABET)
        {
            return false;
        }

        // Use the index for a letter to check if children[index] is a NULL pointer,
        if (cursor->children[index] == NULL)
        {
            // meaning the word does not exist in the trie.
            return false;
        }
        // If children[index] is in fact a node, you can reset cursor to this node and check for the next letter in its children nodes.
        cursor = cursor->children[index];
    }
    return cursor->is_word;
}

// Unload trie from memory
bool unload(void)
{

    // The recursive function handles all of the freeing
    unloader(root);

    return true;
}

void unloader(node *current)
{

    // Iterate over all the children to see if they point to anything and go
    // there if they do point
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }

    // After we check all the children point to null we can get rid of the node
    // and return to the previous iteration of this function.
    free(current);
}