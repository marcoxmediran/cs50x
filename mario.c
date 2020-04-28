#include <cs50.h>
#include <stdio.h>

// Variables
int height;

// Declaring Functions
void printBlank();
void printHash();
void printGap();
void printPyramid();

// Main Function
int main(void)
{
    // Prompts the user for int height from 1 to 8
    do
    {
        height = get_int("Height ");
    }
    while (height < 1 || height > 8);

    // Prints the pyramid
    printPyramid();

    // Tells that the program is done
    return 0;
}

// Function that prints the whole pyramid
void printPyramid(void)
{
    for (int a = 0; a < height; a++)
    {
        printBlank(height - 1 - a);
        printHash(a + 1);
        printGap();
        printHash(a + 1);
        printf("\n");
    }
}

// Function that prints blank tiles
void printBlank(int b)
{
    for (int i = 0; i < b; i++)
    {
        printf(" ");
    }
}

// Function that prints hashes
void printHash(int c)
{
    for (int i = 0; i < c; i++)
    {
        printf("#");
    }
}

// Function that prints the gap between two pyramids
void printGap()
{
    printf("  ");
}
