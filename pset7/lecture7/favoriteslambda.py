# Python has a unique ability that we have not seen to date: It allows for the utilization of anonymous or lambda functions.
# These functions can be utilized when you want to not bother creating an entirely different function. Notice the following modification:

# Sorts favorites by value using lambda function

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
for favorite in sorted(counts, key=lambda language: counts[language], reverse=True):
    print(f"{favorite}: {counts[favorite]}")

# Notice that the get_value function has been removed. Instead, lambda language: counts[language] does in one line what our previous two-line function did.