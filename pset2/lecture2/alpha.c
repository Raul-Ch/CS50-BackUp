#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    // Length -1 because of the '/0' NUL at the end
    for(int i = 0; i < strlen(word)-1; i++)
    {
        // Checl of NOT alphabetical (i.e., "ba")
        if (word[i] > word[i + 1]){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}