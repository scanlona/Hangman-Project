#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char userInput[100];
char userGuesses[100];
char correctWord[] = "chocolate sprinkle donut";
char guessedLetter = 'a';
char unsolvedWord[] = "XXXXXXXXX XXXXXXXX XXXXX";
bool youWon = false;
bool foundTheLetter = false;
bool megaFail = false;
int incorrectGuesses = 0;

void checkForLetter() {
    for (int i = 0; i < strlen(correctWord); i++) {
        if (correctWord[i] == guessedLetter) {
            printf("Letter found!\n");
            unsolvedWord[i] = guessedLetter;
            foundTheLetter = true;
        }
    }
    if (foundTheLetter == false) {
        incorrectGuesses++;
        printf("You got %d incorrect guesses so far.\n", incorrectGuesses);
    }
    if (incorrectGuesses >= 3) {
        printf("Tough break, kid! You stink!\n");
        megaFail = true;
    }
    foundTheLetter = false;
}

void checkForWin() {
    char* anyUnsolved = strchr(unsolvedWord, 'X');
    if (anyUnsolved == NULL) {
        printf("You win!!\n");
        youWon = true;
    }
}

int main() {
    printf("Starting program...\n");
    while (strcmp(userInput, "exit") != 0) {
        printf("\nInput a letter to guess:\n");
        printf("(Enter 'exit' to exit)\n\n");
        scanf("%s", userInput);
        if (strcmp(userInput, "exit") == 0) {
            break;
        }
        guessedLetter = userInput[0];
        printf("\nYou input: %s\n", userInput);
        checkForLetter();
        printf("%s\n\n", unsolvedWord);
        checkForWin();
        if (youWon) {
            printf("\nProgram complete.\n");
            return 0;
        }
        if (megaFail) {
            printf("The correct answer was: %s\n", correctWord);
            printf("\nProgram complete.\n");
            return 0;
        }
    }
    printf("\nProgram complete.\n");
    return 0;
}