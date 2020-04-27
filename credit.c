#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Variables
long cardNumber;
int nDigits = 0;
bool correctDigits = false;

int main(void)
{
    // Prompts user for valid number of digits for a card
    do
    {
        cardNumber = get_long("Number: ");
        nDigits = floor(log10(cardNumber)) + 1;
        if (nDigits == 13 || nDigits == 15 || nDigits == 16)
        {
            correctDigits = true;
        }
        else
        {
            correctDigits = false;
            printf("INVALID\n");
            return 0;
        }
    }
    while (correctDigits == false || cardNumber < 0);
    
    // Gets the digit from the card number 
    int dig1 = cardNumber % 10;
    int dig2 = cardNumber % 100 / 10;
    int dig3 = cardNumber % 1000 / 100;
    int dig4 = cardNumber % 10000 / 1000;
    int dig5 = cardNumber % 100000 / 10000;
    int dig6 = cardNumber % 1000000 / 100000;
    int dig7 = cardNumber % 10000000 / 1000000;
    int dig8 = cardNumber % 100000000 / 10000000;
    int dig9 = cardNumber % 1000000000 / 100000000;
    int dig10 = cardNumber % 10000000000 / 1000000000;
    int dig11 = cardNumber % 100000000000 / 10000000000;
    int dig12 = cardNumber % 1000000000000 / 100000000000;
    int dig13 = cardNumber % 10000000000000 / 1000000000000;
    int dig14 = cardNumber % 100000000000000 / 10000000000000;
    int dig15 = cardNumber % 1000000000000000 / 100000000000000;
    int dig16 = cardNumber % 10000000000000000 / 1000000000000000;

    // Checksum
    int luhn1 = dig2 * 2;
    if (luhn1 > 9)
    {
        luhn1 = 1 + (luhn1 % 10);
    }
    int luhn2 = dig4 * 2;
    if (luhn2 > 9)
    {
        luhn2 = 1 + (luhn2 % 10);
    }
    int luhn3 = dig6 * 2;
    if (luhn3 > 9)
    {
        luhn3 = 1 + (luhn3 % 10);
    }
    int luhn4 = dig8 * 2;
    if (luhn4 > 9)
    {
        luhn4 = 1 + (luhn4 % 10);
    }
    int luhn5 = dig10 * 2;
    if (luhn5 > 9)
    {
        luhn5 = 1 + (luhn5 % 10);
    }
    int luhn6 = dig12 * 2;
    if (luhn6 > 9)
    {
        luhn6 = 1 + (luhn6 % 10);
    }
    int luhn7 = dig14 * 2;
    if (luhn7 > 9)
    {
        luhn7 = 1 + (luhn7 % 10);
    }
    int luhn8 = dig16 * 2;
    if (luhn8 > 9)
    {
        luhn8 = 1 + (luhn8 % 10);
    }


    // Luhn's Algorithm
    int luhn;

    int odd = dig1 + dig3 + dig5 + dig7 + dig9 + dig11 + dig13 + dig15;
    if (nDigits == 13)
    {
        luhn = luhn1 + luhn2 + luhn3 + luhn4 + luhn5 + luhn6 + odd;
    }
    if (nDigits == 15)
    {
        luhn = luhn1 + luhn2 + luhn3 + luhn4 + luhn5 + luhn6 + luhn7 + odd;
    }
    if (nDigits == 16)
    {
        luhn = luhn1 + luhn2 + luhn3 + luhn4 + luhn5 + luhn6 + luhn7 + luhn8 + odd;
    }

    bool correctLuhn = false;
    if (luhn % 10 == 0)
    {
        correctLuhn = true;
    }

    // Tells what type of card
    if (nDigits == 16)
    {
        if (dig16 == 5 && (dig15 == 1 || dig15 == 2 || dig15 == 3 || dig15 == 4 || dig15 == 5))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (dig16 == 4)
        {
            printf("VISA\n");
            return 0;
        }
    }
    if (nDigits == 15 && dig15 == 3 && (dig14 == 4 || dig14 == 7))
    {
        printf("AMEX\n");
        return 0;
    }
    if (nDigits == 13 && dig13 == 4)
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
} 
