#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // INT Promt user for x
    int x = get_int("x: ");

    // INT Promt user for y
    int y = get_int("y: ");

    //Perform addition
    printf("%i\n", x + y);
}