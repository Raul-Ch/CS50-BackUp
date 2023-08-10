#include <stdio.h>

int main (void)
{
    const int n = 3;
    for (int i = 0; i < n; i++)
    {
         for (int i = 0; i < n; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}