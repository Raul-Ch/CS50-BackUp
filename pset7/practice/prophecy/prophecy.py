from cs50 import SQL
import csv

#DB
# Open database
db = SQL("sqlite:///roster.db")

# Open CSV file
with open("students.csv", "r") as file:

    # Create reader
    reader = csv.DictReader(file)

    # Iterate over CSV file,
    for row in reader:
        db.execute("INSERT INTO students (student_name) VALUES (?)",row["students_name"])
        db.execute("INSERT INTO houses (name, house, head) VALUES (? ,? , ?)",row["students_name"])
        db.execute("INSERT INTO students (name, house, head) VALUES (? ,? , ?)",row["students_name"])


        students_Table(students, )

