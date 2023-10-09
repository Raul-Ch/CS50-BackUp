# Averages three numbers using a list and a loop

from cs50 import get_int

# Get scores
scores = []
for i in range(3):
    score = get_int("Score: ")
    scores.append(score)

# Print average
average = sum(scores) / len(scores)
print(f"Average: {average}")

# Notice that you can use the built-in append method, whereby you can append the score to the list
# Also notice that we use the sum function to add all elements in the list.