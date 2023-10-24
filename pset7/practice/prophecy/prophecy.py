import csv

# Lists
students = []
houses = []
heads = []

# Open CSV file
with open("students.csv", "r") as file:

    # Create reader
    reader = csv.DictReader(file)

    # Iterate over CSV file,
    for row in reader:
        print("___________________")
        students = row["student_name"]
        print(students)
        houses = row["house"]
        print(houses)
        heads = row["head"]
        print(heads)
        print("___________________")

