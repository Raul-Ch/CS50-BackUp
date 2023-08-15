#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // We check if the number is greater than 1 an if it is a prime number
    if (number != 1 || number%2 != 0)
    {
        return true;
    }
    // 2 being an even number can divide
    else if (number == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
