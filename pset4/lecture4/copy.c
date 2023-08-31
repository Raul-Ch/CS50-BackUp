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
    printf("t: %p\n", t);
}