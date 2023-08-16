#include <cs50.h>
#include <stdio.h>

int checksum(long credit);
string credit_type(long credit, int length);

int main(void)
{
    // TODO: Prompt for credit card number: "program that prompts the user for a credit card number"
    long credit_number;
    do
    {
        credit_number = get_long("Input the credit card number: ");
    }
    while (credit_number < 999999999999 || credit_number > 9999999999999999);
    // "13 to 16 digit numbers"
    int credit_length = checksum(credit_number);
    if (credit_length != false)
    {
        printf("%s", credit_type(credit_number, credit_length));
    }
}

int checksum(long credit)
{
    bool multiply = false;
    long check;
    int sum = 0;
    int length = 0;

    do
    {
        if (multiply == true)
        {
            // credit /= 10;
            check = credit % 10;
            // Print to check the second to last numbers: printf("Last: %li\n",check*2);
            if (check * 2 > 9)
            {
                sum += 1;
                sum += (check * 2 - 10);
            }
            else
            {
                sum += (check * 2);
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
        length++;
    }
    while (credit > 0);

    if (sum % 10 == 0)
    {
        return length;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

string credit_type(long credit, int length)
{
    length -= 2;
    long type = 1;
    for (int i = 0; i < length; i++)
    {
        type *= 10;
    }
    credit /= type;
    if (credit > 39 && credit < 50)
    {
        credit = 4;
    }
    switch (credit)
    {
        // American Express Numbers
        case 34:
        case 37:
            return "AMEX\n";
            break;
        // Master Card Numbers
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            return "MASTERCARD\n";
            break;
        // Visa Numbers
        case 4:
            return "VISA\n";
            break;
    }
    return 0;
}