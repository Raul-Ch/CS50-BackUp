// LINKED LIST
// Implements a list of numbers using a linked list

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        // *n.number = number->;
        n->number = number;
        n->next = NULL;

        // Prepend node to list
        n->next = list;
        list = n;

    }
        // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

}

/* Notice that what the user inputs at the command line is put into the number field of a
   node called n, and then that node is added to the list. For example, ./list 1 2 will put
   the number 1 into the number field of a node called n, then put a pointer to list into
   the next field of the node, and then update list to point to n. That same process is
   repeated for 2. Next, node *ptr = list creates a temporary variable that points at the
   same spot that list points to. The while prints what at the node ptr points to, and then
   updates ptr to point to the next node in the list. Finally, all the memory is freed. */
