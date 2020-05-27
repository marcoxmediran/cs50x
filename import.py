from sys import argv
from sys import exit
from cs50 import SQL
import csv

# Checks for proper cli argument count
if (len(argv) != 2):
    print("Usage: python import.py characters.csv")
    exit(1)
# Opens databes called 'students.db' to do SQL queries for the program
db = SQL("sqlite:///students.db")

# Opens second argument to open. It must be a csv file
with open(argv[1], "r") as input:
    csv = csv.DictReader(input)
    # Iterates every row of a csv file using DictReader
    for row in csv:
        fName = row["name"].split()
        # A checker if a full name doesn't have a middle name,
        # it will make the second name the last name, and
        # make the middle name blank
        if len(fName) == 2:
            fName.append(fName[1])
            fName[1] = None
        # Inserts data into students.db
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                   fName[0], fName[1], fName[2], row["house"], row["birth"])
# Program ran successfuly
exit(0)