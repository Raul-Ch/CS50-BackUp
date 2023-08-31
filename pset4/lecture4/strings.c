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
    char *t = "HI!";
    printf("%c\n", *t);
    // Notice that we are printing each character at the location of s.
    printf("%c\n", t[0]);
    printf("%c\n", t[1]);
    printf("%c\n", t[2]);
    // Notice that the first character at the location of s is printed. Then, the character at the location s + 1 is printed, and so on.
    printf("%c\n", *t);
    printf("%c\n", *(t + 1));
    printf("%c\n", *(t + 2));
}