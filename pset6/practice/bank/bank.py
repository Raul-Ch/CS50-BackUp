# Prints a command-line argument

from sys import argv

for check in argv:
    if argv[1] == 'Hello':
        print("$0")
        for checkh in argv[1]:
            if checkh == 'H':
                    print("$20")
    else:
        print("$100")