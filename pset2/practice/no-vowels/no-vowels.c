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
    // If we recive exactly one argument after ./no-vowels
    if (argc == 2)
    {
        printf("%s\n", replace(argv[1]));
    }
    else
    {
        printf("Usage: ./no-vowels word\n");
    }
}

string replace(string argv)
{
    for (int i = 0; i < strlen(argv); i++)
    {
        switch (argv[i])
        {
            // We change the vowels (Lower or Upper) to number except for u
            case 'a':
            case 'A':
                argv[i] = '6';
                break;
            case 'e':
            case 'E':
                argv[i] = '3';
                break;
            case 'i':
            case 'I':
                argv[i] = '1';
                break;
            case 'o':
            case 'O':
                argv[i] = '0';
                break;
        }
    }

    return argv;
}
