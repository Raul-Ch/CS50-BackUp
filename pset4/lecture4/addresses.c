#include <stdio.h>

int main(void)
{
    int n = 50;

    // Print value in n
    printf("%i\n", n);
    // Print:
    // & Provides the address of something stored in memory.
    // * Instructs the compiler to go to a location in memory.
    // Notice the %p, which allows us to view the address of a location in memory.
    printf("%p\n",&n);

    int *p = &n;
    //Notice that p is a pointer that contains a number that is the address of an integer n.
    printf("%p\n",p);
    // To illustrate the use of the * operator (prints the integer at the location of p.)
    printf("%i\n", *p);
}