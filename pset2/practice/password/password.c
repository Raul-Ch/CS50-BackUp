// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool check[4] = {false, false, false, false};
    for (int i = 0; i < strlen(password); i++)
    {
        if (check[0] == false)
        {
            if (isupper(password[i]))
            {
                check[0] = true;
            }
        }
        if (check[1] == false)
        {
            if (islower(password[i]))
            {
                check[1] = true;
            }
        }
        if (check[2] == false)
        {
            if (isdigit(password[i]))
            {
                check[2] = true;
            }
        }
        if (check[3] == false)
        {
            if (isalpha(password[i]))
            {
                check[3] = true;
            }
        }
    }
    if (check[0] == true && check[1] == true && check[2] == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
