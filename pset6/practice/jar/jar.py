# self allows an object to refer to its own properties and methods.
class Jar:
    #  This is the constructor method that gets called when you create a new instance of the class
    #  The capacity parameter is optional and defaults to 12 if not provided.
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.size = 0
        if capacity < 0:
            raise ValueError

    # This method returns a string representation of the object.
    # It's what gets printed when you print an instance of the class.
    def __str__(self):
        """Finally, the whole expression is wrapped in {} inside the f-string, which means
        "evaluate this expression and convert the result to a string" """
        return f"{self.size * '🍪'}"

    # This method could be used to add a certain number (n) of items to the jar.
    def deposit(self, n):
       if self.size += n > self.capacity:
            raise ValueError
       else self.size += n


    # This method could be used to remove a certain number (n) of items from the jar.
    def withdraw(self, n):
       if self.size -= n < self.capacity0::
            raise ValueError
       else self.size -= n


    # This is a decorator that allows a method to be accessed like an attribute instead of a method.
    @property
    # This method, decorated with @property, could be used to get the capacity of the jar.
    def capacity(self):
        return self.capacity

    @property
    # This method, also decorated with @property, could be used to get the current number of items in the jar.
    def size(self):
        return size

def main():
