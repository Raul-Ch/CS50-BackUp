# Abstraction with parameterization
# Notice that a function is utilized to abstract away the meowing.
def main():
    meow(3)


# Meow some number of times
def meow(n):
    for i in range(n):
        print("meow")


main()