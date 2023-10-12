# TODO
from cs50 import get_int
from sys import exit


def checksum(credit):
    multiply = False
    check = 0
    sum = 0
    length = 0

    while credit > 0:
        if multiply:
            check = credit % 10
            if check * 2 >= 10:
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
    elif sum % 10 == 0:
        return length
    else:
        exit("INVALID")


# The first two digits of a credit card number are used to identify the card
def credit_type(credit):
    # NOTE: C to PYTHON
    """length -= 2"""
    # The type variable is used to calculate a power of 10,
    """ type = 1
        for i in range(length):
            type *= 10"""
    # which is then used to divide credit. This operation is used to get the first two digits of credit
    """ credit //= type
    """
    # NOTE: BETTER PYTHON SOLUTION
    """ Convert credit to a string"""
    credit_str = str(credit)
    """ and then slice the first two characters"""
    first_two_digits = int(credit_str[:2])

    if 39 < first_two_digits < 50:
        return "VISA"
    elif first_two_digits in [34, 37]:
        return "AMEX"
    elif first_two_digits in range(51, 56):
        return "MASTERCARD"
    else:
        return "INVALID"


credit_number = get_int("Input the credit card number: ")
checksum(credit_number)
print(credit_type(credit_number))
