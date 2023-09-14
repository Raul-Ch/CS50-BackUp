#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    // Width goes 1-2-3-4-5 but arrays go 0-1-2-3-4
    // In the reflect function, we subtract one from the width because arrays in C are zero-indexed.
    // This means that if an image has a width of 'w', the pixels are indexed from 0 to 'w-1'.
    // So, when we want to reflect the image, we need to access the pixel at index 'w-1' (which is the last pixel)
    // and not 'w' (which would be out of bounds).
    width -= 1;
    for (int i = 0; i < height; i++)
    {
        // we divide the width by two because as we change de pixels at the middle there are all changed
        for (int j = 0; j < (width/2); j++)
        {
            // Saving last pixel
            temp = image[i][width - j];
            // Changing last pixel for the first one
            image[i][width - j] = image[i][j];
            // Changing first pixel with the temp (last pixel)
            image[i][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
