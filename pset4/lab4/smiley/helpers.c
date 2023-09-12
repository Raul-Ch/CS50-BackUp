#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(image[height][width].rgbtBlue == (255) || image[height][width].rgbtGreen == (255) || image[height][width].rgbtRed == (255))
            {
                image[height][width].rgbtBlue = (20);
            }
        }
    }
}
