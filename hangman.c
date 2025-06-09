#include <stdio.h>
#include <string.h>

char userInput[100];
char userGuesses[100];

int main() {
    printf("Starting program...\n");
    while (strcmp(userInput, "exit") != 0) {
        printf("\nInput a letter to guess:\n");
        printf("(Enter 'exit' to exit)\n\n");
        scanf("%s", userInput);
        if (strcmp(userInput, "exit") == 0) {
            break;
        }
        strcat(userGuesses, userInput);
        printf("\nYou input: %s\n", userGuesses);
    }
    printf("\nProgram complete.\n");
    return 0;
}