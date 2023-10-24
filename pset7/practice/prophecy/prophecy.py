from cs50 import SQL
import csv

#LISTS
students = []
houses = []
assignments = []

def students_Table(student):
    students.append({"Student": student})

def houses_Table(house, head):
    if not any(h['House'] == house for h in houses):
        houses.append({"House": house, "Head": head})

def assignments_Table(student, house):
    assignments.append({"Student": student, "House": house})

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

        students_Table(student)
        houses_Table(house, head)
        assignments_Table(student, house)

    for student in students:
        db.execute("INSERT INTO students (student_name) VALUES (?)", student["Student"])

    for house in houses:
        db.execute("INSERT INTO houses (house, head) VALUES (?,?)", house["House"], house["Head"], )

    for assignment in assignments:
        student_id = db.execute("SELECT id FROM students WHERE student_name = ?", assignment["Student"])[0]['id']
        house_id = db.execute("SELECT id FROM houses WHERE house = ?", assignment["House"])[0]['id']
        
        db.execute("INSERT INTO assignments (id_students, id_houses) VALUES (?, ?)", student_id, house_id)


"""     print(houses)
    print(students)
    print(assignments) """