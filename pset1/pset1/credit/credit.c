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
        check = credit % module;
        printf("%li\n",check);
        sum += check;
        module -= 10;
        credit /= 100;
        }
        while (check > 0);
}