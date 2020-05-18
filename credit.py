from cs50 import get_int
from sys import exit


# Main Funtion
def main():
    # Prompts user
    card = get_int("Number: ")
    if len(str(card)) not in [16, 15, 13]:
        print("INVALID")
        exit(1)
    strCard = str(card)
    nDigits = len(strCard)
    # Reverses the digits
    revCard = strCard[nDigits:: - 1]
    # Converts Digits to a list
    Digits = []
    for i in range(nDigits):
        Digits.append(int(revCard[i]))
    Dig = []
    for i in range(nDigits):
        Dig.append(int(revCard[i]))
    # The Luhn's Algorithm
    # Checksum (even place)
    a = 1
    for i in range(int(nDigits / 2)):
        Digits[a] *= 2
        if Digits[a] > 9:
            Digits[a] = (Digits[a] % 10) + 1
        a += 2
    # Checker
    luhnSum = 0
    for i in range(nDigits):
        luhnSum += Digits[i]
    if luhnSum % 10 == 0:
        # VISA
        if nDigits == 16 and Dig[15] == 4:
            print("VISA")
            exit(0)
        elif nDigits == 13 and Dig[12] == 4:
            print("VISA")
            exit(0)
        # MASTERCARD
        elif nDigits == 16 and Dig[15] == 5 and Dig[14] in [1, 2, 3, 4, 5]:
            print("MASTERCARD")
            exit(0)
        elif nDigits == 15 and Dig[14] == 3 and Dig[13] in [3, 7]:
            print("AMEX")
            exit(0)
        else:
            print("INVALID")
            exit(1)
    else:
        print("INVALID")
        exit(1)


main()