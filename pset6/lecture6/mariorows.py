#Notice that you can override the behavior of the print function to stay on the same line as the previous print.

for i in range(4):
    print("?", end="")
print()


# Similar in spirit to previous iterations, we can further simplify this program:
# Prints a row of 4 question marks without a loop

print("?" * 4)

# Notice that we can utilize * to multiply the print statement to repeat 4 times.

# Prints a 3-by-3 grid of bricks with loops


"""What about a large block of bricks?"""
for i in range(3):
    for j in range(3):
        print("#", end="")
    print()

# Notice how one for loop exists inside another. The print statement adds a new line at the end of each row of bricks.
