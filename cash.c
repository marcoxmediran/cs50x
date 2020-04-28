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

int main(void)
{
    // Prompts the user for the change owed
    do
    {
        owedF = get_float("Change owed: ");
    }
    while (owedF < 0);

    // Failproofs the prompted float
    owedF += 0.001;
    owedI = owedF * 100;

    // Greedy Algorithm
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
    // Prints the answer from the greedy algorithm
    printf("%i\n", coins);

    // Tells that the program is done
    return 0;
}
