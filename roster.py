from sys import argv
from sys import exit
from cs50 import SQL

# Checks for correct cli argument count
if (len(argv) != 2):
    print("Usage: python roster.py 'House Name'")
    exit(1)
# Opens databes called 'students.db' to do SQL queries for the program
db = SQL("sqlite:///students.db")
# Saves second argument as the house name
house = argv[1]

# Query program
res = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last ASC, first ASC", house)
for row in res:
    first = row["first"].strip()
    last = row["last"].strip()
    birth = str(row["birth"]).strip()
    if row["middle"] == None:
        print(f"{first} {last}, born {birth}")
    else:
        middle = row["middle"].strip()
        print(f"{first} {middle} {last}, born {birth}")
# Program ran successfuly
exit(0)