# TODO
from cs50 import get_int

# prompt the user with get_int
# positive integer between 1 and 8, inclusive
# re-prompt if wrong
while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break

# For each row of the pyramid depending on his height
# i starts in 0
i = 1
for i in range(height + 1):
    # Print the leading spaces for the left pyramid
    # SPACE * (3 - 0 - 1) = 2 spaces with no /n
    print(" " * (height - i), end="")
    # Then we print the "#", multiplied by the row we are at
    # NOTE that: 1 of height one #, 2 equal ## and lvl 3 its also ###
    print("#" * (i), end="")
    # Then we print ALWAYS the space between pyramids
    print("  ", end="")
    # We do the simple pyramid method # * i iteration + 1 (cause we start at 0)
    print("#" * (i))
