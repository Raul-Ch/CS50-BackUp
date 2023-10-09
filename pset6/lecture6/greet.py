# Prints a command-line argument

from sys import argv

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")

# Notice that argv[1] is printed using a formatted string,
# noted by the f present in the print statement.

# Printing command-line arguments, indexing into argv
print("-All-")
for i in range(len(argv)):
    print(argv[i])

# Printing command-line arguments using a slice
print("-Slice-")
for arg in argv[1:]:
    print(arg)
