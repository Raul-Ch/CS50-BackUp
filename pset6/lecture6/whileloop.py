# In C
""" // Demonstrates while loop

#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
} """

# In Python
# Demonstrates while loop

print("While:")
i = 0
while i < 3:
    print("meow")
    i += 1

print("----------------------")

# Better design
print("For")
for i in range(3):
    print("meow")

