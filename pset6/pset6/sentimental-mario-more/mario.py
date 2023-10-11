# TODO
from cs50 import get_int

# prompt the user with get_int
# positive integer between 1 and 8, inclusive
# re-prompt if wrong
while True:
    size = get_int("Height: ")
    if 1 <= size <= 8:
        break

for size in height:
    print(f'{#*size}')