# In C
""" // Logical operators

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to agree
    char c = get_char("Do you agree? ");

    // Check whether agreed
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}" """

# In Python
# Conditionals, Boolean expressions, relational operators

from cs50 import get_string

# Prompt user for integers
s = get_string("Do you agree? ")

# Check whether agreed
if s == 'Y' or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")

#  two vertical bars utilized in C is replaced with or.

# Another approach to this same code could be as follows:
# Logical operators, using lists

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

# Check whether agreed
if s in ["y","Y" ,"yes"]:
    print("Agreed.")
elif s in ["n", "N", "no"]:
    print("Not agreed.")

# Notice how we are able to express multiple keywords like y and yes.
