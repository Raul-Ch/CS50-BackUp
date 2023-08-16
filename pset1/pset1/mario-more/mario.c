#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for size: " let’s allow the user to decide just how tall the pyramids should be"
    int size;
    do
    {
        size = get_int("Input the size of the pyramids (1-8): ");
    }
    while (size < 0 || size > 8);
}