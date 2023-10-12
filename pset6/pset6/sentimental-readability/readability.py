# TODO

# Convert the input string into a list of words,
# with split() -> This method splits a string into a list where each word is a separate element.
text = input("Text: ")

# Now, words is a list of words.
words_list = text.split()

# Number of words
words = len(words_list)

# Get the number of letters with len(words).
letters = 0
sentences = 0

for letter in words_list:
    for char in letter:
        if char.isalpha():
            letters += 1
    if letter.endswith((".", "!", "?")):
        sentences += 1

"""print(words, letters, sentences)"""

# "Where 'L' is the average number of letters per 100 words in the text"
L = (letters / words) * 100
# And 'S' is the average number of sentences per 100 words in the text."
S = (sentences / words) * 100

CL_Index = int(0.0588 * L - 0.296 * S - 15.8)

if CL_Index < 1:
    print("Before Grade 1")

elif CL_Index > 16:
    print("Grade 16+")

else:
    print(f"Grade {CL_Index}")
