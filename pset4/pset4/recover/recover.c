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
        printf("Could not open file: %s.\n", argv[1]);
        return 1;
    }


    for(int i = 0; i < )
    {
        fread()
    }

}