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
    // Placeholder float to store RGB Values when swapping different RGB Values on two different pixels
    float tempRed;
    float tempGreen;
    float tempBlue;
    // This loops iterates over each pixel of the image then swaps each pixel's
    // RGB Values to its mirror Pixel
    for (int i = 0; i < height; i++)
    {
        // Second condition uses width divided by 2 since we move
        // TWO pixel at each loop
        // NOTE: Middle pixels will not be swapped since they are not in
        // the scope of width divided by 2
        for (int j = 0; j < width / 2; j++)
        {
            // Copy pixel's RGB Values to temp floats
            tempRed = image[i][j].rgbtRed;
            tempGreen = image[i][j].rgbtGreen;
            tempBlue = image[i][j].rgbtBlue;
            // Using the width variable, we can access the remaining half of the picture
            // to swap with it's mirror pixel
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            // Since the other half is swaped, we alter the other half's RGB Values
            // with our temp RGB Values
            image[i][width - j - 1].rgbtRed = tempRed;
            image[i][width - j - 1].rgbtGreen = tempGreen;
            image[i][width - j - 1].rgbtBlue = tempBlue;
        }
    }
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
