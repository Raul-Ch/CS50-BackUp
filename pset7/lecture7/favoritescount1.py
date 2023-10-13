#Python allows us to use a dictionary to count the counts of each language. Consider the following improvement upon our code:
# Counts favorites using dictionary

import csv

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    counts = {}

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

# Print counts
for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")

# Notice that the value in counts with the key favorite is incremented when it exists already. If it does not exist, we define counts[favorite] and set it to 1.
# Further, the formatted string has been improved to present the counts[favorite].