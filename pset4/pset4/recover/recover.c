#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
    FILE *f = fopen(argv[1], "r");

    // Prepare files
    FILE *jpeg = NULL;

    if (f == NULL)
    {
        printf("Could not open file: %s.\n", argv[1]);
        return 1;
    }

    // Repeat a read until end of card
    // Read 512 bytes into a buffer
    // unsigned 8-bit integer and can represent values from 0 to 255
    uint8_t buffer[BYTES_SIZE];

    int number_jpg = 0;

    // this while loop continues to read data from the file f into the buffer as long as fread is able to read BYTES_SIZE
    // read through a file in chunks of BYTES_SIZE until there's no more data to read.
    while (fread(&buffer, 1, BYTES_SIZE, f) == BYTES_SIZE)
    {
        // If first JPEG
        // ..else ....
        // & bitwie and, compares each bit of the first operand to the corresponding bit of the second operand.
        // == 0xe0 checks if the switches that lit up match the pattern 11100000 (which is 0xe0). If they do, the whole statement is true!
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg != NULL)
            {
                fclose(jpeg);
                number_jpg++;
            }

            // You need space for three digits, the extension, and the null terminator
            char *filename = malloc(8 * sizeof(char));

            // Implement jpeg format of name starting at 000.jpeg
            sprintf(filename, "%03i.jpg", number_jpg);

            // Create that file
            jpeg = fopen(filename, "w");
            free(filename);

            // Write on the file
            fwrite(&buffer, 1, BYTES_SIZE, jpeg);        }
        else
        {
            if ((jpeg != NULL))
            {
                fwrite(&buffer, 1, BYTES_SIZE, jpeg);
            }
        }
    }
    fclose(jpeg);
    fclose(f);
}