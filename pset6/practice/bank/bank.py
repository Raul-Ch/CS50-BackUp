# In a file called bank.py, implement a program that prompts the user for a greeting.
# If the greeting starts with “hello”, output $0. If the greeting starts with an “h” (but not “hello”),
# output $20. Otherwise, output $100. Ignore any leading whitespace in the user’s greeting, and treat
# the user’s greeting case-insensitively.

from sys import argv

for check in argv:
    if (check.upper() == "Hello"):
        print("$0")
        break
    else:
        for check2 in check[0:1]:
            if (check2.upper() == "H"):
                 print("$20")
                 break
            else:
                print("$100")
                break