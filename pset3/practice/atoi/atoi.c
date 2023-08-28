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
    int length = strlen(input);
    // TODO
    if (length == 0)
    {
        return;
    }
    // a - '0' is equivalent to ((int)a) - ((int)'0'), which means the ascii values of the characters are subtracted from each other.
    // The idea is to use the ASCII value of the digits from 0 to 9 start from 48 – 57.
    int numeric = input[length - 1] - 48;
    input[length - 1] = '/0';

    return numeric + 10 * convert(input);
}