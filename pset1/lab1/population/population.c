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
   calculate_years(start, end);
    // TODO: Print number of years
}

int calculate_years(int start, int end)
{
    int years;
    float population = start;
    float born;
    float die;
    do
    {
        born = start / 3;
        die = start / 4;
        poplation = start;(int) born ;
    }
    while (start = end);

    return years;
}