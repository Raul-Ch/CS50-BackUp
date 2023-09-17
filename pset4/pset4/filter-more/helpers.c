#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtGreen + image[i][j].rgbtRed + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_pixel;
    // Width goes 1-2-3-4-5 but arrays go 0-1-2-3-4
    // In the reflect function, we subtract one from the width because arrays in C are zero-indexed.
    // This means that if an image has a width of 'w', the pixels are indexed from 0 to 'w-1'.
    // So, when we want to reflect the image, we need to access the pixel at index 'w-1' (which is the last pixel)
    // and not 'w' (which would be out of bounds).
    width -= 1;
    for (int i = 0; i < height; i++)
    {
        // we divide the width by two because as we change de pixels at the middle there are all changed
        for (int j = 0; j < round(width / 2.0); j++)
        {
            // Saving last pixel
            temp_pixel = image[i][width - j];
            // Changing last pixel for the first one
            image[i][width - j] = image[i][j];
            // Changing first pixel with the temp (last pixel)
            image[i][j] = temp_pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float average_red = 0;
    float average_green = 0;
    float average_blue = 0;
    RGBTRIPLE **temp_image = malloc(height *sizeof(RGBTRIPLE*));
    for (int i = 0; i < height; i++)
    {
        temp_image[i] = malloc(width * sizeof(RGBTRIPLE));
        for (int j = 0; j < width; j++)
        {
            temp_image[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // ensure that you're not accessing pixels outside the image
            for (int column = 0; column < 3; column++)
            {
                for(int row = 0; row < 3; row++)
                {
                    if (i - 1 < 0 || i + 1 >= width)
                    {
                        row ++;
                    }
                    else if (j - 1 < 0 || j + 1 >= height)
                    {
                        row ++;
                    }
                    average_red += temp_image[i + column][j + row].rgbtRed;
                    average_green += temp_image[i + column][j + row].rgbtGreen;
                    average_blue += temp_image[i + column][j + row].rgbtBlue;

                    image[i][j].rgbtRed = round(average_red / 3.0);
                    image[i][j].rgbtGreen = round(average_green / 3.0);
                    image[i][j].rgbtBlue = round(average_blue / 3.0);
                }
            }
        }
    }
        free(temp_image);
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
