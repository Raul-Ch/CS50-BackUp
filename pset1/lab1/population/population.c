#include <cs50.h>
#include <stdio.h>

int calculate_years(int start, int end);

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Input the start size of the population: ");
    }
    while (start < 9);
    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("Input the desired end size of the population: ");
    }
    while (end < start);
    // TODO: Calculate number of years until we reach threshold
    // TODO: Print number of years
    // cs50/labs/2023/x/population not admitted output:
    // printf("Years to achive de desired population: %i\n",calculate_years(start, end));
    printf("Years: %i\n", calculate_years(start, end));
}

int calculate_years(int start, int end)
{
    int years = 0;
    float born;
    float pass;
    while (start < end)
    {
        born = start / 3;
        pass = start / 4;
        start += born - pass;
        years++;
    }
    return years;
}