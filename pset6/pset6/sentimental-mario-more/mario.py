# TODO
from cs50 import get_int

# prompt the user with get_int
# positive integer between 1 and 8, inclusive
# re-prompt if wrong
while True:
    size = get_int("Height: ")
    if 1 <= size <= 8:
        break

# For each row (the height) of the pyramid
for height in range(size):
    # Print the leading spaces for the left pyramid
    print(" " * (size - height - 1), end="")
    #
    print("#" * (height + 1), end="")
    print("  ", end="")
    print("#" * (height + 1))
