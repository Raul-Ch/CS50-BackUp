""" # Saves names and numbers to a CSV file

import csv

# Get name and number
name = input("Name: ")
number = input("Number: ")

# Open CSV file
with open("phonebookcsv.csv", "a") as file:

    # Print to file
    writer = csv.writer(file)
    writer.writerow([name, number])

# Notice with block of code, with the writer and its work happening below it indented,
# prevents us from needing to close our file once finished. """

# Commonly, CSV files have columns that carry specific names.
# A DictWriter can used to create the CSV file and assign specific names to each column.

# Saves names and numbers to a CSV file using a DictWriter

import csv

# Get name and number
name = input("Name: ")
number = input("Number: ")

# Open CSV file
with open("phonebookcsv.csv", "a") as file:

    # Print to file
    # Notice the name and number columns are defined in the penultimate row of code,
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    # and values are added in the final line.
    writer.writerow({"name": name, "number": number})