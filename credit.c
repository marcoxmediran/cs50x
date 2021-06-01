#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Function Prototypes
int getLength(long cardNumber);
string luhn(long card, int length);

int main(void)
{
    // Get input from user
    long card = get_long("Number: ");
    
    // Count digits
    int length = getLength(card);

    // Program ran successfuly
    printf("%s\n", luhn(card, length));
    return 0;
}

// Count how many digits the card has
int getLength(long cardNumber)
{
    int cardLength = log10(round(cardNumber)) + 1;
    return cardLength;
}

// Function to check card validity and type
string luhn(long card, int length)
{
    string cardType = "INVALID";
    int validator = 0;
    
    // Applies algorithm on digits what will not be doubled 
    int singleLength = length / 2;
    if (singleLength % 2 != 0)
    {
        singleLength++;
    }
    long cardSingle = card;
    for (int i = 0; i < singleLength; i++)
    {
        int toAdd = cardSingle % 10;
        cardSingle /= 100;
        validator += toAdd;
    }

    // Applies algorithm on digits that will be doubled
    int doubleLength = length / 2;
    long cardDouble = card;
    cardDouble /= 10;
    for (int i = 0; i < doubleLength; i++)
    {
       int toDouble = 2 * (cardDouble % 10);
       if (toDouble >= 10)
       {
           toDouble = toDouble % 10 + 1;
       }
       cardDouble /= 100;
       validator += toDouble;
    }

    // If card is valid, indentify card type
    if (validator % 2 == 0)
    {
        // Gets 2 starting numbers from the left
        int startNums = card / (long)pow(10, length - 2);
        
        // Check if card type is American Express
        if (length == 15 && ((startNums == 37) || (startNums == 34)))
        {
            cardType = "AMEX";
        }
        // Check if card type is MasterCard or Visa
        else if (length == 16)
        {
            // MasterCard
            if ((startNums >= 51) && (startNums <= 55))
            {
                cardType = "MASTERCARD";
            }
            // Visa
            if (startNums / 10 == 4)
            {
                cardType = "VISA";
            }
        }
        else if ((length == 13) && (startNums / 10 == 4))
        {
            cardType = "VISA";
        }
    }

    return cardType;
}
