# TODO

# Convert the input string into a list of words,
# with split() -> This method splits a string into a list where each word is a separate element.
text = input("Text: ")

# Now, words is a list of words.
word = text.split()

# Number of words
words = len(word)

# Get the number of letters with len(words).
letters = 0
sentences = 0

for letter in word:
        letters =+ 1
        print(letter)
        if letter == '.':
            sentences =+ 1

print(words, letters, sentences)