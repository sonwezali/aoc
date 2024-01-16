#include <stdio.h>
#define MAX_SIZE 1000

int isNumeric(char c)
{
    return c >= '0' && c <= '9';
}

int main()
{
    FILE *file;
    char line[MAX_SIZE];

    file = fopen("input.txt", "r");
    
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }   

    int totalSum = 0;

    while (fgets(line, MAX_SIZE, file) != NULL)
    {
        char firstNum = '\0';
        char lastNum = '\0';

        for (int i = 0; line[i] != '\0'; i++)
        {
            if (isNumeric(line[i])) 
            {
                if (firstNum == '\0') 
                {
                    firstNum = line[i]; 
                }
                else 
                {
                    lastNum = line[i];
                }
            }
        }

        int lineNum;
        if (lastNum == '\0') 
        {
            lineNum = (int) (firstNum - '0') * 10 + (int) (firstNum - '0');
        }
        else
        {
            lineNum = (int) (firstNum - '0') * 10 + (int) (lastNum - '0');
        }

        totalSum += lineNum;
    }

    fclose(file);
    
    printf("Total sum: %d\n", totalSum);

    return 0;
}

