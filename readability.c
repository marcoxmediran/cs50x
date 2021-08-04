#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Prototypes
int countLetters(string sentence);
int countWords(string sentence);
int countSentences(string sentence);

int main(void)
{
    // Prompt for text and compute values
    string sentence = get_string("Text: ");
    int letters = countLetters(sentence);
    int words = countWords(sentence);
    int sentences = countSentences(sentence);

    // Computes readability index using the Coleman-Liau formula
    int index = round(0.0588 * (100.0 * letters / words) - 0.296 * (100.0 * sentences / words) - 15.8);
    // Prints answer and program exits
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
    return 0;
}

// Counts alphabetic characters given a string
int countLetters(string sentence)
{
    // Iterates over each character and increases letters by 1
    // if character is an alphabet letter
    int letters = 0;
    for (int i = 0, length = strlen(sentence); i < length; i++)
    {
        if (isalpha(sentence[i]))
        {
            letters++; 
        }    
    }
    return letters;
}

// Counts number of words given a string
int countWords(string sentence)
{
    // Iterates over each character and increases letters by 1
    // if character is a space
    int words = 0;
    if ((int) strlen(sentence) != 0)
    {
        words++;
    }
    for (int i = 0, length = strlen(sentence); i < length; i++)
    {
        if (sentence[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

// Counts number of sentences given a string
int countSentences(string sentence)
{
    // Iterates over each character and increases sentences by 1
    // if character is either a dot, exclamation, or question mark
    int sentences = 0;
    for (int i = 0, length = strlen(sentence); i < length; i++)
    {
        char c = sentence[i];
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
