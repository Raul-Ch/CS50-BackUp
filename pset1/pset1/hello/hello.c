#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Promt user for his name
    string name = get_string("What's your name?: ");
    // Display greetings
    printf("Hello, %s!\n", name);
}