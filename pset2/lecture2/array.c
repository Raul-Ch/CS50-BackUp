#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length;
    // Get the length from the user
    do
    {
        length = get_int("Length: ");
    }
    while (length < 1);
    // Declare our array
    int twice[length];
    // Set the first value
    twice[0] = 1;
    printf("%i\n",twice[0]);

    for (int i = 1; i < length; i++)
    {
        // Make the current element twice the previous and print
        twice[i] = 2 * twice [i - 1];
        printf("%i\n",twice[i]);
    }

}