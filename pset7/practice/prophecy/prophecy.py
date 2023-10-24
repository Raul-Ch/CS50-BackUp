# Inserts into DB

import csv

from cs50 import SQL

# Open database
db = SQL("sqlite:///roster.db")


# Insert
for _ in range(4):
    # Prompt user for houses
    house = input("House: ")
    head = input("House Head: ")
    insert = db.execute("INSERT INTO houses (house, head) VALUES (?, ?);", house, head)

