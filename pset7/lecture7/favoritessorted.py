# If you look at the parameters for the sorted function in the Python documentation, you will find it has many built-in parameters.
# You can leverage some of these built-in parameters as follows:

# Sorts favorites by value

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

def get_value(language):
    return counts[language]

# Print counts
for favorite in sorted(counts, key=get_value, reverse=True):
    print(f"{favorite}: {counts[favorite]}")

# Notice that a function called get_value is created, and that the function itself is passed in as an argument to the sorted function.
# The key argument allows you to tell Python the method you wish to use to sort items.