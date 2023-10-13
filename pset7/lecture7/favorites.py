# Prints all favorites in CSV using csv.reader

import csv

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create reader
    reader = csv.reader(file)

    # Skip header row
    next(reader)

    # Iterate over CSV file, printing each favorite
    for row in reader:
        print(row[1])

# Notice that the csv library is imported. Further, we created a reader that will hold the result of csv.reader(file).
# The csv.reader function reads each row from the file, and in our code we store the results in reader. print(row[1]), therefore, will print the language from the favorites.csv file.