// Prepends numbers to a linked list, using while loop to print

#include <CS50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main()