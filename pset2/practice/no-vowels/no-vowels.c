// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input);

int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./no-vowels word\n");
    }
    else
    {
    printf("%s",replace(argv[1]));
    }
}

string replace(string argv)
{
    string newargv;

    for (int i = 0; strlen(argv) < i; i++)
    {
        switch (argv[i])
        {
            case: 'a'
        }
    }

    return newargv;
}
