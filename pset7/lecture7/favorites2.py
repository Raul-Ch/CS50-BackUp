# Python also allows you to index by the keys of a list. Modify your code as follows:

# Prints all favorites in CSV using csv.DictReader

import csv

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Iterate over CSV file, printing each favorite
    for row in reader:
        print(row["language"])

# Notice that this example directly utilizes the language key in the print statement.