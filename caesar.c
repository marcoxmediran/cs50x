// Libraries
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Global Variables
string plainText;
int key;

// Custom Functions
string getText(void);
string caesarMessage(string text);
void errorMessage(void);

// Main Function
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]))
            {
                errorMessage();
                return 1;
            }
            else if (isdigit(argv[1][i]))
            {
                key = atoi(argv[1]);
            }
        }
    }
    else
    {
        errorMessage();
        return 1;
    }

    // Prompts for text
    getText();

    // Enciphers the text
    caesarMessage(plainText);
    // Prints the Enciphered text
    printf("ciphertext: %s\n", plainText);

    // Tells that the program ran successfully
    return 0;
}

// Prompts for plainText while no input is given
string getText(void)
{
    do
    {
        plainText = get_string("plaintext: ");
    }
    while (strlen(plainText) < 1);

    return plainText;
}

// Uses the caesar cryptology to encrypt the message
string caesarMessage(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                plainText[i] = text[i] - 65;
                plainText[i] = (plainText[i] + key) % 26;
                plainText[i] = plainText[i] + 65;
            }
            else if (islower(text[i]))
            {
                plainText[i] = text[i] - 97;
                plainText[i] = (plainText[i] + key) % 26;
                plainText[i] = plainText[i] + 97;
            }
        }
    }
    return plainText;
}

// Prints error/usage hint
void errorMessage(void)
{
    printf("Usage: ./caesar key\n");
}