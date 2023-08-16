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
    print_pyramids(size);
}

void print_pyramids(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int space = 0; space <= i; space++)
        {
             printf("#");
        }
        for(int j = 0; j <= i; j++)
        {
             printf("#");
        }
        printf("\n");
    }
}