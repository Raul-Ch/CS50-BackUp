from cs50 import SQL
import csv

#LISTS
students = []
houses = []
assignments = []

def houses_Table(house, head):
    if house not in houses:
        houses.append({"House": house, "Head": head})



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
        houses_Table(house, head)
        #assignments_Table( )

    print(houses)