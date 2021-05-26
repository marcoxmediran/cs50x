#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    
    //  Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // Calculate number of years until we reach threshold
    int years = 0;
    while (start < end)
    {
        int toAdd = (float)(start / 3) - (float)(start / 4);
        start += toAdd;
        years++;
    }
    
    // Print number of years
    printf("Years: %i\n", years);

    // Program ran successfuly
    return 0;
}
