# TODO
from cs50 import get_string

# Get the text from user
text = get_string("Text: ")
text = text.lower()

# Calculate the number of letters
letter_count = 0
for i in text:
    if i >= "a" and i <= "z":
        letter_count += 1

# Calculate the number of words
word_count = 1
for i in text:
    if i == " ":
        word_count += 1

# Calculate the number of sentences
sentence_count = 0
for i in text:
    if i == "." or i == "!" or i == "?":
        sentence_count += 1

# Calculate The Coleman-Liau index
L = letter_count / word_count * 100
S = sentence_count / word_count * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

# Print the output
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(index))