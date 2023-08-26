#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    // a - '0' is equivalent to ((int)a) - ((int)'0'), which means the ascii values of the characters are subtracted from each other.
    // The idea is to use the ASCII value of the digits from 0 to 9 start from 48 – 57.
    int n = strlen(input) - 1;
    int new = input[n] - 48;

    return last;
}