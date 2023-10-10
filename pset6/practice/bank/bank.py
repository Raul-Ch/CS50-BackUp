# In a file called bank.py, implement a program that prompts the user for a greeting.
# If the greeting starts with “hello”, output $0. If the greeting starts with an “h” (but not “hello”),
# output $20. Otherwise, output $100. Ignore any leading whitespace in the user’s greeting, and treat
# the user’s greeting case-insensitively.

from cs50 import get_string

prompt = get_string("Greetings: ")
print(prompt[0])
if (prompt[0].upper() == "HELLO"):
        print("$0")
else:
    for check in prompt[0:1]:
        if (check.upper() == "H"):
            print("$20")
        else:
            print("$100")