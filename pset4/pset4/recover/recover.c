#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Correct Usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open input file
    FILE *f = fopen(argv[1],"r");
    if (f == NULL)
    {
        printf("Could not open file: %s.\n", f);
        return 4;
    }
}