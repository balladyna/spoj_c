#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getArray();

int main() {
  int testNo, iteration;

  scanf("%d\n", &testNo);
  for (iteration = 0; iteration < testNo; iteration++) {
    char userInput;
    char array[10000];
    char *inputArray = array;
    int len = 0, size = 1;

    while ((userInput = getchar()) != '\n' && userInput != EOF && len < sizeof(array) - 1) {
      inputArray[len] = userInput;
      len++;
      if (userInput == ' ') {
        size++;
      }
    }
    inputArray[len] = '\0';

    int newArray[size];
    int position = size - 1;

    while (*inputArray) {
      if (isdigit(*inputArray)) {
        int number = strtol(inputArray, &inputArray, 10);
        newArray[position] = number;
        --position;
      } else {
        inputArray++;
      }
    }

    for (int i = 0; i < (size - 1); i++) {
      printf("%d ", newArray[i]);
    }
    printf("\n");
  }
  return 0;
}
