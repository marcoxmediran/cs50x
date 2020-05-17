from cs50 import get_float
from sys import exit

# Global Variables
quarter = 25
dime = 10
nickel = 5
penny = 1


# Main Function
def main():
    coins = 0
    # Gets a non-negative float from a user
    while True:
        owed = get_float("Change owed: ")
        if owed >= 0:
            break
    # Multiplies and round the owed float to do math with coins
    owed *= 100
    owed = round(owed)

    # Greedy Algorithm
    while owed > 0:
        if owed >= quarter:
            coins += 1
            owed -= quarter
        elif owed >= dime:
            coins += 1
            owed -= dime
        elif owed >= nickel:
            coins += 1
            owed -= nickel
        else:
            coins += 1
            owed -= penny
    # Prints how many coins needed from Greedy Algoritm
    print(coins)
    # Program ran successfully
    exit(0)


main()