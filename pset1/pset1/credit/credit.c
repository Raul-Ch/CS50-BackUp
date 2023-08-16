#include <cs50.h>
#include <stdio.h>

bool checksum (long credit);
int card_type (int length);

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
    if (checksum (credit_number) == true)
    {
        printf("%li",credit_number);
    }
    else if ((checksum (credit_number) == false))
    {
        printf("INVALID\n");
    }
}

bool checksum (long credit)
{
    bool multiply = false;
    long check;
    int sum = 0;

    do
    {
        if (multiply == true)
        {
                //credit /= 10;
                    check = credit % 10;
                    // Print to check the second to last numbers: printf("Last: %li\n",check*2);
                    if (check*2 > 9)
                    {
                        sum += 1;
                        sum += (check*2-10);
                    }
                    else
                    {
                    sum += (check*2);
                    }
                    // Print to check proper sum: printf("Sum: %i\n",sum);
                    credit /= 10;
                    multiply = false;
        }
        else if (multiply == false)
        {
                    check = credit % 10;
                    sum += check;
                    credit /= 10;
                    multiply = true;
        }
        lenght ++;
    }
    while (credit > 0);

    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}