#include <stdio.h>
#include <stddef.h>
#include <string.h>

typedef struct {
    const char *word;
    int value;
} NumberMapping;

int isNumeric(char c)
{
    return c >= '0' && c <= '9';
}

int wordToNumber(const char *word) {
    NumberMapping mappings[] = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };
    
    int result = 0;

    for (size_t i = 0; i < sizeof(mappings)/sizeof(mappings[0]); i++) {
        if (strcmp(word, mappings[i].word) == 0) {
            result = mappings[i].value;
            break;
        }
    }

    return result;
}

int main() {
    const char *input = "nine";

    printf("Input is: %d", wordToNumber(input));
}
