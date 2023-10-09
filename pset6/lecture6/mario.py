# Prints a column of bricks, using a helper function to get input

from cs50 import get_int


def main():
    height = get_height()
    for i in range(height):
        print("#")


def get_height():
    while True:
        # Notice that try is utilized to attempt to convert n to an integer.
        # If it cannot do so, an error is outputted.
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an integer")


main()