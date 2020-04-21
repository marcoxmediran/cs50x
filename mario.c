#include <cs50.h>
#include <stdio.h>

// Variables 
int height;

// Custom Functions
void printBlank();
void printHash();
void printSpace();
void printPyramid();

// Main Function
int main(void)
{
    // Prompts the user for an integer from 1 to 8
    do 
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //Prints the mario pyramid
    printPyramid();

    // This tells that the program ran successfully
    return 0;
}

// Function that prints the pyramid using the other custom functions
void printPyramid(void)
{
    for (int a = 0; a < height; a++)
    {
        printBlank(height - 1 - a);   
        printHash(a + 1);
        printSpace();
        printHash(a + 1);
        printf("\n"); 
    }
}

void printBlank(int b)
{
    for(int i = 0; i < b; i++)
    {
        printf(" ");
    }
}

void printHash(int c)
{
    for(int i = 0; i < c; i++)
    {
        printf("#");
    }
}

void printSpace()
{
    printf("  ");
}


