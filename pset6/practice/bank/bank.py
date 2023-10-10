# In a file called bank.py, implement a program that prompts the user for a greeting.
# If the greeting starts with “hello”, output $0. If the greeting starts with an “h” (but not “hello”),
# output $20. Otherwise, output $100. Ignore any leading whitespace in the user’s greeting, and treat
# the user’s greeting case-insensitively.

# Strips both rigth and left
prompt = input("Greetings: ").strip()
# This method returns True if the string starts with the specified value, and False otherwise.
if (prompt.lower().startswith("hello")):
    print("$0")
else:
    if (prompt[0].lower() == "h"):
        print("$20")
    else:
        print("$100")