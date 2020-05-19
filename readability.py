from cs50 import get_string

# Prompts the user for the text
text = get_string("Text: ")
# Counts how many words are in the string
words = len(text.split())
letters = 0
sentences = 0
for i in range(len(text)):
    # Counts how many letters are present in the text
    if (ord(text[i]) >= 65 and ord(text[i]) <= 90) or (ord(text[i]) >= 97 and ord(text[i]) <= 122):
        letters += 1
    # Counts how many sentences are present in the text
    elif ord(text[i]) in [33, 46, 63]:
        sentences += 1
# Coleman-Liau Formula
L = (100 / words) * letters
S = (100 / words) * sentences
index = round(0.0588 * L - 0.296 * S - 15.8)
# Prints the index
if index < 1:
    print("Before Grade 1")
elif index >= 1 and index <= 16:
    print(f"Grade {index}")
else:
    print("Grade 16+")