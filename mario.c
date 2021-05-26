#include <stdio.h>
#include <cs50.h>

// Function Prototypes
void mario(int n);
void printSpaces(int h, int r);
void printHashes(int h, int r);

int main(void)
{
    // Prompt user for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
   
    // Program ran successfuly
    mario(height);
    return 0;
}

void mario(int h)
{
    // Print every row of pyramid
    for (int rows = 0; rows < h; rows++)
    {
        printSpaces(h, rows);
        printHashes(h, rows);
        printf("  ");
        printHashes(h, rows);
        printf("\n");
    }
}

// Function to print spaces given height and row
void printSpaces(int h, int r)
{
    for (int spaces = h - 1; spaces > r; spaces--)
    {
        printf(" ");
    }
}

// Function to print hashes given height and row
void printHashes(int h, int r)
{
    for (int hashes = 0; hashes < r + 1; hashes++)
    {
        printf("#");
    }
}
