#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
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
    char *original = get_string("\nReal Copy\ns: ");

    // Allocate memory for another string
    char *copy = malloc(strlen(original) + 1);
    // Notice that malloc(strlen(s) + 1) creates a block of memory that is the length of the string s plus one.
    // This allows for the inclusion of the null \0 character in our final, copied string.

    // Copy string into memory, including '\0'
    // CHANGE i <= strlen(s) FOR n = strlen(copy); i <= n; i++
    // It’s best not to call unneeded functions in the middle condition of the for loop, as it will run over and over again.
    // strlen() only runs once.
    for (int i = 0; n = strlen(copy); i <= n; i++)
    {
        copy[i] = original[i];
    }

    // Capitalize copy
    copy[0] = toupper(t[0]);

    // Print strings
    printf("s: %s\n", original);
    printf("s: %p\n", original);
    printf("t: %s\n", copy);
    printf("s: %p\n", copy);

}