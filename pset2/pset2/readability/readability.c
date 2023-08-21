#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    // Input
    string text = get_string("Text: ");
    // Count letters
    printf("%i letters\n",count_letters(text));
}

int count_letters(string text)
{
    // Checks if all of the characters in the provided string, text, are alphabetic.
    // In the standard C locale letters are just [A-Za-z] and ctype_alpha() is equivalent to (ctype_upper($text) || ctype_lower($text))
    int letters = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    //  For the purpose of this problem, we’ll consider any sequence of characters separated by a space to be a word
    int words = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}