# TODO
from cs50 import get_int

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
        print("INVALID")
    elif (sum % 10 == 0):
        return length
    else:
        print("INVALID")



credit_number = get_int("Input the credit card number: ")
checksum(credit_number)


