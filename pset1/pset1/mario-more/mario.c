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
    while (size < 1 || size > 8);
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
        // We start at 0, so there will be one space more to the number of height of the tower
        // So we need to add 1 to start counting from that number
        for(int space = i+1; space < size; space++)
        {
             printf(" ");
        }
        // Here we just print the character (depending on the row) to build the pyramid
        for(int j = 0; j <= i; j++)
        {
             printf("#");
        }
        // The space between pyramids
        printf ("  ");
        // We print the rigth tower
        for(int k = 0; k <= i; k++)
        {
             printf("#");
        }
        printf("\n");
    }
}