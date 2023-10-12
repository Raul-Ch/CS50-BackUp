# TODO
from cs50 import get_int
from sys import exit

def checksum(credit):
    multiply = False
    check = 0
    sum = 0
    length = 0

    while(credit > 0):
        if multiply:
            check = credit % 10
            if (check * 2 >= 10):
                sum += 1
                sum += check * 2 - 10
            else:
                sum += check * 2
        # The // operator in Python performs integer division, which is equivalent to the / operator in C when both operands are integers.
            credit //= 10
            multiply = False
        else:
            check = credit % 10
            sum += check
            credit //= 10
            multiply = True
        length += 1

    if not (13 <= length <= 16):
        exit("INVALID")
    elif (sum % 10 == 0):
        return length
    else:
        exit("INVALID")

def credit_type(credit, length):
    length -= 2
    type = 1


credit_number = get_int("Input the credit card number: ")
credit_type(credit_number, checksum(credit_number)):
