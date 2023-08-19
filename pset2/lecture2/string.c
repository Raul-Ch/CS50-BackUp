#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = "Emma";
    for (int i = 0; i < strlen(name); i++)
    {
        printf("%c = ",name[i]);
        printf("%i\n",name[i]);
    }
}