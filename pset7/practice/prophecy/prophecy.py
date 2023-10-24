from cs50 import SQL
import csv

#LISTS
students = []
houses = []
assignments = []

def houses_Table(house):
    if house not in houses:
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

