#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    // Get a string
    string s = get_string("s: ");

    // Copy strings address
        // Notice that string t = s copies the address of s to t
    string t = s;

    // Capitalize first letter in string
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print string twice
    printf("s: %p\n", s);
    printf("s: %s\n", s);
    printf("t: %p\n", t);
    printf("t: %s\n\n", t);

    // Crete an authentic copy of our string as follows:
    char *copy = get_string("\nReal Copys: ");

    // Allocate memory for another string
    char *t = malloc(strlen(copy) + 1);
    // Notice that malloc(strlen(s) + 1) creates a block of memory that is the length of the string s plus one.
    // This allows for the inclusion of the null \0 character in our final, copied string.

    // Copy string into memory, including '\0'
    for (int i = 0; i <= strlen(s); i++)
    {
        t[i] = copy[i];
    }

    // Capitalize copy
    t[0] = toupper(t[0]);

    // Print strings
    printf("s: %s\n", copy);
    printf("t: %s\n", t);

}