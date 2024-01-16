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

    /*while (fgets(line, MAX_SIZE, file) != NULL)
    {
        printf("%s", line);
    }*/

    fgets(line, MAX_SIZE, file);
    fgets(line, MAX_SIZE, file);

    printf("%s\n", line);

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

    printf("firstNum = %c\nlastNum = %c", firstNum, lastNum);

    fclose(file);
    
    return 0;
}

