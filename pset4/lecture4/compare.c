#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Print strings
    printf("%s\n", s);
    // Print strings' addresses
    printf("%p\n", s);
    // Print strings
    printf("%s\n", t);
    // Print strings' addresses
    printf("%p\n", t);
}