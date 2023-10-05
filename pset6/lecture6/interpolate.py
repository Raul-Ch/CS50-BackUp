# get_string and print, with format strings

from cs50 import get_string

answer = get_string("What's your name? ")
print(f"hello, {answer}")

# print("hello, " + answer) = print(f"hello, {answer}")
#Notice how the curly braces allow for the print function to interpolate the answer such that answer appears within.
