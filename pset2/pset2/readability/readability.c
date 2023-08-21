#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Input
    string text = get_string("Text: ");
    // Test:
    // // Count letters
    // printf("%i letters\n",count_letters(text));
    // // Count words
    // printf("%i words\n",count_words(text));
    // // Count sentences
    // printf("%i sentences\n",count_sentences(text));

    // "Where 'L' is the average number of letters per 100 words in the text"
    float L = (count_letters(text) + count_words(text)) * 100;
    // "And 'S' is the average number of sentences per 100 words in the text."
    float S = (count_sentences(text) + count_words(text)) * 100;

    int index = 0.0588 * L - 0.296 * S - 15.8;

    switch ()
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
    //  Count words: "For the purpose of this problem, we’ll consider any sequence of characters separated by a space to be a word"
    int words = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        // && for: ""You are, of course, welcome to attempt a solution that will tolerate multiple spaces between words or indeed, no words!"
        if (text[i] == 32 && text[i-1] != 32 && text[i+1] != 32)
        {
            words++;
        }
    }
    // We count spaces but the "end/final" word just ends with a point or nothing to track the last space
    return words + 1;
}

int count_sentences(string text)
{
    //  Note: "For this problem, we’ll ask you to ignore that subtlety: you should consider any sequence of characters that ends with:
    //  a . or a ! or a ? to be a sentence "
    int sentences = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}