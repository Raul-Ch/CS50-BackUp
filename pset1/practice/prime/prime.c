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
    // There is only one even prime number, 2.
    // And 3 it's an odd but "base" number
    // Both 2 and 3 can be used to divide multiples
    if (number == 2 || number == 3)
    {
        return true;
    }
    // Zero and One are not a prime numbers
    // If the number can be divided by 2 or by 3 then it is not a prime number since it has more than two divisors.
    else if (number == 1 || number % 2 == 0 || number % 3 == 0)
    {
        return false;
    }
    // If it does not divide by 2 or 3 then it can't be divided b
    else
    {
        return true;
    }
}
