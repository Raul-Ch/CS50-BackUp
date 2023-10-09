# List with he following syntax:

# Averages three numbers using a list and a loop with + operator

from cs50 import get_int

# Get scores
scores = []
for i in range(3):
    score = get_int("Score: ")
    scores += [score]

# Print average
average = sum(scores) / len(scores)
print(f"Average: {average}")

# Notice that += is utilized to append the score to the list.
# In this case we place square brackets around score because only a list can be added to another list using + or +=.