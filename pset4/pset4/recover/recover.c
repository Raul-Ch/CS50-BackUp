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

    // Open memory card
    FILE *f = fopen(argv[1],"r");

    if (f == NULL)
    {
        printf("Could not open file: %s.\n", argv[1]);
        return 1;
    }

    // Repeat a read until end of card
    // Read 512 bytes into a buffer
       BYTE  *buffer = 512;
    // If first JPEG
    // ..else ....
    // If already found JPEG
    // Close any remaining file

}