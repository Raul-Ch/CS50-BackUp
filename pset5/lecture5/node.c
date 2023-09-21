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

}