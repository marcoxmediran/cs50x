#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Prototypes
string encryptText(string input, string key);

int main(int argc, string argv[])
{
    // Makes sure that argc is equal to 1
    string key = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Does checks if key is complete
    else if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Does checks if each character in the key is an alphabetic character
    // Also checks if there are no duplicate characters
    else
    {
        int checker = 0;
        for (int i = 0, length = strlen(key); i < length; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            else
            {
                key[i] = toupper(key[i]);
                checker += (int) key[i];
            }
        }
        if (checker != 2015)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    // Accepts input from user then prints the encrypted input
    string input = get_string("plaintext: ");
    printf("ciphertext: %s\n", encryptText(input, key));
    return 0;
}

// Custom function to encrypt input using the Substitution Encryption
// given the input and a key
string encryptText(string input, string key)
{
    // Iterates through eacher character in the input
    for (int i = 0, length = strlen(input); i < length; i++)
    {
        // Checks if character is an alphabetic character
        if (isalpha(input[i]))
        {
            // Makes sure to get a correct place in the alphabet
            int buffer;
            if (isupper(input[i]))
            {
                buffer = 65;
            }
            else
            {
                buffer = 97;
            }
            // Replaces the character from input to its corresponding character
            // from the key
            int place = input[i] - buffer;
            input[i] = key[place];
            // Corrects casing of characters
            if (buffer == 97)
            {
                input[i] = tolower(input[i]);
            }
        }
    }
    return input;
}
