#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary placeholders for RGB values
    float tempRed;
    float tempGreen;
    float tempBlue;
    // Average Value
    float ave;
    // This loop copies each value to temp variables then calculates the average
    // that will be applied to each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempRed = image[i][j].rgbtRed;
            tempGreen = image[i][j].rgbtGreen;
            tempBlue = image[i][j].rgbtBlue;
            ave = (tempRed + tempGreen + tempBlue) / 3.00;
            image[i][j].rgbtRed = roundf(ave);
            image[i][j].rgbtGreen = roundf(ave);
            image[i][j].rgbtBlue = roundf(ave);
        }
    }
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
