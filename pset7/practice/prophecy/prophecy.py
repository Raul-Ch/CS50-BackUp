import csv

# Lists
students = []
houses = []
assignments = []

# Open CSV file
with open("students.csv", "r") as file:

    # Create reader
    reader = csv.reader(file)

    # Iterate over CSV file, printing each favorite
    for row in reader:
        students = row["student_name"]
        houses = row["house"]
        assignments = row["student_name"]
