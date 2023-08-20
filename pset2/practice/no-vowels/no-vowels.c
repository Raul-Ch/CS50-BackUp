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
        printf("%s\n", replace(argv[1]));
    }
}

string replace(string argv)
{
    for (int i = 0; i < strlen(argv); i++)
    {
        switch (argv[i])
        {
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
                argv[i] = 'u';
                break;
        }
    }

    return argv;
}
