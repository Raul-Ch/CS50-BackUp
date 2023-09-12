// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // Header its the array the memory buffer
    uint8_t header[HEADER_SIZE] = {0};

    // sizeof header tells us the size units
    // finally 44 as the qty of bytes we are reading
    fread(header,sizeof(*header),HEADER_SIZE,input);

    fwrite(header,sizeof(*header),HEADER_SIZE,output);
    fclose(output);

    // TODO: Read samples from input file and write updated data to output file
    // Append the samples not re-write
    FILE *outputa = fopen(argv[2], "a");
    if (outputa == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int16_t buffer;
    fread(&buffer,sizeof(buffer),feof(input),input);
    // Close files
    fclose(input);
    fclose(outputa);
}
