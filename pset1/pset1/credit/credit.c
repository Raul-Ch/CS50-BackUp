#include <cs50.h>
#include <stdio.h>

int main(void)
{
     // TODO: Prompt for credit card number: "program that prompts the user for a credit card number"
    double credit_number;
    do
    {
        credit_number = get_double("Input the credit card number: ");
    }
    while (credit_number < 1000000000000 || credit_number > 9999999999999999);
}