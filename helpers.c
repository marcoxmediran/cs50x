#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float tempRed = 0;
    float tempGreen = 0;
    float tempBlue = 0;
    for (int i = 0; i < height - 1; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            tempRed = image[height][width].rgbtRed;
            tempGreen = image[height][width].rgbtGreen;
            tempBlue = image[height][width].rgbtBlue;
            float aveF = (tempRed + tempGreen + tempBlue) / 3;
            int aveI = round(aveF);
            image[height][width].rgbtRed = aveI;
            image[height][width].rgbtGreen = aveI;
            image[height][width].rgbtBlue = aveI;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
