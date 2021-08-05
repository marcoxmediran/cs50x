#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

// Prototypes
bool isCorrectKey(string argv);
string encryptText(string input, int key);

int main(int argc, string argv[])
{
    // Computes argument into an int if argument count is equal to 2
    int key;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (!isCorrectKey(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        key = atoi(argv[1]) % 26;
    }

    string input;
    do
    {
        input = get_string("plaintext: ");
    }
    while (strlen(input) == 0);

    // Encrypts the text input
    string output = encryptText(input, key);
    printf("ciphertext: %s\n", output);
    return 0;
}

// Iterates through each character given a string and checks
// whether each character is a digit
bool isCorrectKey(string argv)
{
    for (int i = 0, length = strlen(argv); i < length; i++)
    {
        // Checks if character is a digit and alphanumeric
        if (!isalnum(argv[i]))
        {
            return false;
        }
        // Checks if character is alphanumeric
        else if (isalnum(argv[i]) && isalpha(argv[i]))
        {
            return false;
        }
    }
    return true;
}

// Iterates through eacher character given a string and applies
// Caesar encryption
string encryptText(string input, int key)
{
    // Makes ascii value to zero then apply the formula for
    // Caesar encryption
    for (int i = 0, length = strlen(input); i < length; i++)
    {
        if (isalpha(input[i]))
        {
            int buffer;
            if (isupper(input[i]))
            {
                buffer = 65;
            }
            else
            {
                buffer = 97;
            }
            input[i] -= buffer;
            input[i] = (input[i] + key) % 26;
            input[i] += buffer;
        }
    }
    return input;
}
