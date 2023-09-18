#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Number of bytes in .JPEG header
const int BYTES_SIZE = 512;

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
    int8_t buffer[BYTES_SIZE];
    
    while (fread(&buffer, sizeof(1), BYTES_SIZE, f) == BYTES_SIZE)
    {
        // If first JPEG
        // ..else ....
        if (buffer[0] == 0xff && buffer[1] == 0xd8  && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            printf("Horray");
        }
        // If already found JPEG
        // Close any remaining file
    }

}