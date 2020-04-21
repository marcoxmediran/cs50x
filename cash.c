// Libraries
#include <stdio.h>
#include <cs50.h>

// Variables
int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;
float owedF;
int owedI;
int coins = 0;

// Custom Functions
void greedy();

int main(void)
{
    // Prompts the user for float
    do
    {
        owedF = get_float("Change owed: ");
    }
    while (owedF < 0);
    owedF += 0.001;
    owedI = owedF * 100;

    // Custom function that does the greedy algorithm ;)
    greedy();

    // Prints the least number of coins owed using the greedy algorithm
    printf("%i\n", coins);

    // Tells that the program ran successfully
    return 0;
}

void greedy(void)
{
    while (owedI > 0)
    {
        if (owedI >= quarter)
        {
            coins++;
            owedI -= quarter;
        }
        else if (owedI >= dime)
        {
            coins++;
            owedI -= dime;
        }
        else if (owedI >= nickel)
        {
            coins++;
            owedI -= nickel;
        }
        else
        {
            coins++;
            owedI -= penny;
        }
    }
}
