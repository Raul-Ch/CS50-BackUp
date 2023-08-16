#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user to agree -> Preguntar al usuario si esta de acuerdo
    char c = get_char("Do you agree? ");

    //Check whether agreed -> Verificar si accedio/esta de acuerdo
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}