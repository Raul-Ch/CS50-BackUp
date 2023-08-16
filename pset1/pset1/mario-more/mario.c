#include <cs50.h>
#include <stdio.h>

void print_pyramids(int size);

int main(void)
{
    // TODO: Prompt for size: " let’s allow the user to decide just how tall the pyramids should be"
    int size;
    do
    {
        size = get_int("Input the size of the pyramids (1-8): ");
    }
    while (size < 0 || size > 8);
    // "positive integer between, say, 1 and 8, inclusive"
    // Call the function and pass the size
    print_pyramids(size);
}

    // Function to print the pyramids
void print_pyramids(int size)
{
    // Cicle to print size (heigth)
    for(int i = 0; i < size; i++)
    {
        //Cicles to print the width
        // Here we print out the spaces (Depending on the row is the number of spaces)
        for(int space = i; space < size; space++)
        {
             printf(".");
        }
        // Here we just print the character (depending on the row) to build the pyramid
        for(int j = 0; j <= i; j++)
        {
             printf("#");
        }
        printf("\n");
    }
}