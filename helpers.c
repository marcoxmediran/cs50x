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
            tempRed = image[i][j].rgbtRed;
            tempGreen = image[i][j].rgbtGreen;
            tempBlue = image[i][j].rgbtBlue;
            float ave = (tempRed + tempGreen + tempBlue) / 3.00;
            image[i][j].rgbtRed = roundf(ave);
            image[i][j].rgbtGreen = roundf(ave);
            image[i][j].rgbtBlue = roundf(ave);
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
