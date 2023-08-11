#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Double Promt user for x
    double x = get_double("x: ");

    // Double Promt user for y
    double y = get_double("y: ");

    //Perfom division
    //float z = (float) x / (float) y;
    double z = (float) x / (float) y;
    //Truncate float value
    printf("%0.20f\n",z);
}