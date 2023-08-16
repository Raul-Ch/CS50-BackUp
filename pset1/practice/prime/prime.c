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
    // 1.- Zero and One are not a prime numbers
    // 2.- Any number greater than 2 that is a multiple of 2 is not a prime, since it has at least three divisors:
    // 3.- Any number greater than 3 that is a multiple of 3 is not a prime, since it has 1, 3, and the number itself as divisors.
    // 4.- Any number greater than 5 that is a multiple of 5 is not a prime. (So ​​the only prime number that ends with a 0 or 5 is 5.)
    else if (number == 1 || number % 2 == 0 || number % 3 == 0 || number % 5 == 0)
    {
        return false;
    }
    // If it does not divide by 2, 3 or 5 then it can't be divided by any other than 1 and itself
    else
    {
        return true;
    }
}
