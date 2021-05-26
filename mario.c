#include <stdio.h>
#include <cs50.h>

// Function Prototypes
void mario(int n);

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

void mario(int n)
{
    // Print every row of pyramid
    for (int rows = 0; rows < n; rows++)
    {
        // Print spaces
        for (int spaces = n - 1; spaces > rows; spaces--)
        {
            printf(" ");
        }
        // Print hashes
        for (int hashes = 0; hashes < rows + 1; hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}
