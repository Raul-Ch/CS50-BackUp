# Uppercases string one character at a time

before = input("Before: ")
print("After:  ", end="")
for c in before:
    print(c.upper(), end="")
print()

# Notice that each character is uppercased one at a time.

"""Python has a built-in method for strs. You could modify your code as follows:"""
# Uppercases string all at once

before = input("Before: ")
after = before.upper()
print(f"After:  {after}")
# Notice the upper method is utilized to uppercase the entire string at once.