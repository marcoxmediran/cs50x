#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Initialize Functions
int greedy(int owed);

int main(void)
{
    // Prompt user for owed cash
    int owed;
    do
    {
        owed = round(get_float("Change owed: ") * 100);
    }
    while (owed < 0);

    // Print answer using greedy algorithm
    printf("%i\n", greedy(owed));
    return 0;
}

// Greedy algorithm
int greedy(int owed)
{
    int answer = 0;
    answer += owed / 25;
    answer += (owed % 25) / 10;
    answer += (owed % 25 % 10) / 5;
    answer += (owed % 5);
    return answer;
}
