// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    // We make a variable by dividing the amount of tax given by 100 to represent %
    float half_tax = tax / 100;
    // Then we multiply the % by the amount of the bill
    half_tax *= bill;
    // Finally we get the total of the bill with the tax
    half_tax += bill;

    // we make a variable of type float, with the int tip cast as a float, to obtain it's %
    float half_tip = ((float) tip / 100);
    // Then we multiply the % by the amount of the bill with tax
    half_tip *= half_tax;

    // At last, we add up the bill with tax and the tip, for out total and we divide it by 2
    float total = (half_tip + half_tax) / 2;

    return total;
}
