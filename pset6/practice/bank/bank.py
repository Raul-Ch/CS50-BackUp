# Prints a command-line argument

from sys import argv

if argv[2] == 'Hello':
    print("$0")
else if argv[2]:
    print("hello, world")
