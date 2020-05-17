# Creates a mario half pyramid

from cs50 import get_int
from sys import exit


def main():
    # Prompts the user for an integer from 1 to 8
    while True:
        height = get_int("Height: ")
        if height >= 1 and height <= 8:
            break
    # Prints the half mario pyramid
    for i in range(height):
        printBlank(height - 1 - i)
        printHash(i + 1)
        printSpace()
        printHash(i + 1)
        print()
    # Program ran successfully
    exit(0)


# Prints the blank spaces
def printBlank(b):
    for i in range(b):
        print(" ", end="")


# Prints the hashes/blocks
def printHash(h):
    for i in range(h):
        print("#", end="")


# Prints a space between the half pyramids
def printSpace():
    print("  ", end="")


main()