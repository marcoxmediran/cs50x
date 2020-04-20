#include <cs50.h>
#include <stdio.h>

// Variables
int height;

// Custom Functions
void printSpace();
void printHash();
void printPyramid();

int main(void)
{

    // Prompts the user for an integer from 1 to 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Prints the mario pyramid
    printPyramid();
    // Indicates the program ran successfuly
    return 0;
}

// This functions print the pyramid. I decided to make this as a function to make the main function cleaner
void printPyramid(void)
{
    for (int a = 0; a < height; a++)
    {
        printSpace(height - 1 - a);
        printHash(a + 1);
        printf("\n");
    }
}

// Prints spaces before hashes
void printSpace(int b)
{
    for (int i = 0; i < b; i++)
    {
        printf(" ");
    }
}

// Prints hashes after spaces
void printHash(int c)
{
    for (int i = 0; i < c; i++)
    {
        printf("#");
    }
}
