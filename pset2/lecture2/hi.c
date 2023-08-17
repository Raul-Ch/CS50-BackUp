#include <cs50.h>
#include <stdio.h>

// Notice that this will output the decimal values of each character.
// int main(void)
// {
//     char c1 = 'H';
//     char c2 = 'I';
//     char c3 = '!';

//     printf("%i %i %i\n", c1, c2, c3);
// }

//Notice how the printf statement presents three values from our array called s.
int main(void)
{
    string s = "HI!";
    string t = "BYE!";
    string u = "TEST!";
    printf("%i %i %i\n", s[0], s[1], s[2]);
    printf("%s\n",t);
}