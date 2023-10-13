#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  char userInput;

  while ((userInput = getchar()) != EOF) {
    char array[1000];
    char *inputArray = array;
    char symbol = '\0';
    int len = 0, size = 0;

    while (userInput != '\n' && userInput != EOF && len < sizeof(array) - 1 ) {
      inputArray[len] = userInput;
      len++;
      if (userInput == ' ') {
        size++;
      }
      userInput = getchar();
    }
    inputArray[len] = '\0';

    int *newArray = malloc(size * sizeof(int));
    if (newArray == NULL) {
      exit(EXIT_FAILURE);
    }

    int position = 0;

    while (*inputArray) {
      if (isdigit(*inputArray)) {
        int32_t number = strtol(inputArray, &inputArray, 10);
        newArray[position] = number;
        ++position;
      } else if (*inputArray != ' ') {
        symbol = *inputArray;
        printf("%c\n", symbol);
        inputArray++;
      } else {
        inputArray++;
      }
    }

    printf("%c %d %d\n", symbol, newArray[0], newArray[1]);

    if (symbol == '+') {
      printf("%d\n", (newArray[0] + newArray[1]));
    } else if (symbol == '-') {
      printf("%d\n", (newArray[0] - newArray[1]));
    } else if (symbol == '/') {
      printf("%d\n", (newArray[0] / newArray[1]));
    } else if (symbol == '*') {
      printf("%d\n", (newArray[0] * newArray[1]));
    } else if (symbol == '%') {
      printf("%d\n", newArray[0] % newArray[1]);
    }
    free(newArray);
  }

  return 0;
}