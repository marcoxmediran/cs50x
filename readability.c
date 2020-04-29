#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// Global Variables
string Text;
float letters = 0;
float words = 0;
float sentences = 0;

float indexInitial;
int indexFinal;
float L;
float S;

// Custom Functions
float getLetters(string text);
float getWords(string text);
float getSentences(string text);
int indexFormula();

// Main Function
int main(void)
{
    // Prompts the user for the text
    do
    {
        Text = get_string("Text: ");
    }
    while (strlen(Text) < 1);

    // Count the letters
    getLetters(Text);

    // Count the words
    getWords(Text);

    // Count the sentences
    getSentences(Text);

    // Readability Formula to get Coleman-Liau index
    indexFormula();

    // Prints output
    if (indexFinal < 1)
    {
        printf("Below Grade 1\n");
        return 0;
    }
    else if (indexFinal >= 1 && indexFinal <= 16)
    {
        printf("Grade %i\n", indexFinal);
        return 0;
    }
    else
    {
        printf("Grade 16+\n");
        return 0;
    }
}

// Gets the number of letters from the text
float getLetters(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 65 && text[i] <= 122)
        {
            letters++;
        }
    }
    return letters;
}

// Gets the numbers of words from the text
float getWords(string text)
{
    words++;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isascii(text[i]) && isspace(text[i + 1]))
        {
            words++;
        }
    }
    return words;
}

float getSentences(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}

int indexFormula(void)
{
    L = (100 / words) * letters;
    S = (100 / words) * sentences;
    indexInitial = (0.0588 * L - 0.296 * S - 15.8);
    indexFinal = round(indexInitial);
    return indexFinal;
}