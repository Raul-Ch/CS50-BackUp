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
    double check;
    int module = 100;
    int sum = 0;

        check = credit % module;
        printf("%f\n",check);

        do
        {

        // sum += check;
        // module -= 10;
        }
        while (check > 0);
}