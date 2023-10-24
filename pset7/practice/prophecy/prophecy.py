from cs50 import SQL
import csv

#LISTS
students = []
houses = []
assignments = []

def house_Table(house):
    for check in houses:
        if check != houses:
            houses.append(house)



#DB
# Open database
db = SQL("sqlite:///roster.db")

# Open CSV file
with open("students.csv", "r") as file:

    # Create reader
    reader = csv.DictReader(file)

    # Iterate over CSV file,
    for row in reader:
        student = row["student_name"]
        house = row["house"]
        head = row["head"]

        #students_Table(student, )
        houses_Table(house)
        #assignments_Table( )

