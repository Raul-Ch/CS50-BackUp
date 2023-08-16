#include <cs50.h>
#include <stdio.h>

void checksum (long credit);

int main(void)
{
     // TODO: Prompt for credit card number: "program that prompts the user for a credit card number"
    long credit_number;
    do
    {
        credit_number = get_long("Input the credit card number: ");
    }
    while (credit_number < 1000000000000 || credit_number > 9999999999999999);
    // "13 to 16 digit numbers"
    checksum (credit_number);
}

void checksum (long credit)
{
    long check;
    int module = 10;
    int sum = 0;

        do
        {
        credit /= 10;
        check = credit % module;
        check *= 2;
        // Print to check the numbers
        printf("Last: %li\n",check*2);
        if (check > 9)
        {
            sum += (check/10);
        }
        sum += (check*2);
        printf("Sum: %i\n",sum);
        credit /= 10;
        }
        while (credit > 0);
    printf("%i\n",sum);
}