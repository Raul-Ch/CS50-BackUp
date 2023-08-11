#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // INT Promt user for x
    //int x = get_int("x: ");

    // INT Promt user for y
    //int y = get_int("y: ");

    // Double Promt user for x
    double x = get_double("x: ");

    // Double Promt user for y
    double y = get_double("y: ");

    float z = (float) x / (float) y;

    //Perform addition
    printf("%.4f\n", x + y);
}