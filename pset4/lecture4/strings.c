#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prints the memory locations of each character in the string s.
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    // Present the string that starts at the location of s.
    char *st = "HI!";
    printf("%c\n", st);
}