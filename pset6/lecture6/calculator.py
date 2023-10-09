# Addition with int [using input]
"""
# Prompt user for x
x = input("x: ")
# Prompt user for y
y = input("y: ")
the interpreter understood x and y to be strings."""

# fix your code by employing the int function as follows:
# Prompt user for x
x = int(input("x: "))

# Prompt user for y
y = int(input("y: "))

# Perform addition
print("Addition")
print(x + y)

# Divide x by y
print("Division")
z = x / y
print(z)
print("Division:imprecision")
print(f"{z:.50f}")
# While one could utilize a main function, it is not required.