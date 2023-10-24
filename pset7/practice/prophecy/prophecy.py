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

        students = row["student_name"]
        houses = row["house"]
        heads = row["head"]



        students_Table(students, )

