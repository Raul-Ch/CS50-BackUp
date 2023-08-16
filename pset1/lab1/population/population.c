#include <cs50.h>
#include <stdio.h>

int calculate_years(int start, int end);

int main(void)
{
    // TODO: Prompt for start size: "Your program should first prompt the user for a starting population size."
    int start;
    do
    {
        start = get_int("Input the start size of the population: ");
    }
    while (start < 9);
    // "If we start with fewer than 9 llamas, the population of llamas will quickly become stagnant"

    // TODO: Prompt for end size: "Your program should then prompt the user for an ending population size."
    int end;
    do
    {
        end = get_int("Input the desired end size of the population: ");
    }
    while (end < start);
    // "If the user enters a number less than the starting population size, the user should be re-prompted to enter an ending population"

    // TODO: Calculate number of years until we reach threshold
    // TODO: Print number of years
    // Here, we print an integer, result of the function calculate_years, passing the start and end variables.
    printf("Years: %i\n", calculate_years(start, end));
}

    //Function to calculate years
int calculate_years(int start, int end)
{
    int years = 0;
    // It stops after start reaches the desired population end
    while (start < end)
    {
        // "Each year, n / 3 new llamas are born, and n / 4 llamas pass away."
        // "Int division will truncate the decimals"
        start += (start / 3) - (start / 4);
        // Each loop we increment the count of the years
        years++;
    }
    // We return the variable int years obtained
    return years;
}