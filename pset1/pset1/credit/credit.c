#include <cs50.h>
#include <stdio.h>

void checksum (int credit);

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

void checksum (int credit)
{
    long check;

        check = credit % 10;
        printf("%li\n",check);

}