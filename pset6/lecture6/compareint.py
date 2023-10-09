# In C
""" / Conditionals, Boolean expressions, relational operators

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for integers
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    // Compare integers
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
} """

# In Python
# Conditionals, Boolean expressions, relational operators
from cs50 import get_int

# Prompt user for integers
""" You need not declare the type of the variable."""
x = get_int("What's x? ")
y = get_int("What's y? ")

# Compare integers
""" Notice that there are no more curly braces. Instead, indentations are utilized."""
if x < y:
    print("x is lees than y")
""" Further, elif replaces else if."""
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")