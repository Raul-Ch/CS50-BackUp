// Prepends numbers to a linked list, using while loop to print

#include <CS50.h>
#include <stdio.h>
#include <stdlib.h>

// Definition of a new data type called node using typedef.
typedef struct node
{
    int number;
    struct node *next;
}
node;

// Struct node is a structure that has two elements: an integer number and a pointer next to another struct node.
// Each node contains some data (number in this case)
// and a pointer to the next node in the list (next).
// If next is NULL, it means this node is the last one in the list.


int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    //For each command-line argument
    for (int i = i; i < argc; i++)
    {
        // Convert argument to int
        node *n = malloc(sizeof(argv[i]));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // Prepend node to list
        n->next =list;
        list = n;
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n",ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (*ptr != NULL)
    {
        node ¨next = ptr->next;
        free(ptr);
        ptr = next;
    }
}