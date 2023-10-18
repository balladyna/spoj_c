#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int indexOne, indexTwo;
  char userInput;
  int iteration = 0;

  scanf("%d %d", &indexOne, &indexTwo);

  getchar();

  int newArray[indexTwo][indexOne];

  while ((userInput = getchar()) != EOF) {
    char inputArray[1000];
    int len = 0;

    if (iteration >= indexOne) {
      printf("Yes");
      break;
    }

    while (userInput != '\n' && userInput != EOF) {
      inputArray[len] = userInput;
      len++;
      userInput = getchar();
    }
    inputArray[len] = '\0';

    int index = 0;

    char *ptr = inputArray;

    while (*ptr) {
      if (isdigit(*ptr)) {
        int number = strtol(ptr, &ptr, 10);
        newArray[index][iteration] = number;
        index++;
      } else {
        ptr++;
      }
    }
    iteration++;
    if (iteration >= indexOne) {
      break;
    }
  }

  for (int row = 0; row < indexTwo; row++) {
    for (int col = 0; col < indexOne; col++) {
      printf("%d ", newArray[row][col]);
    }
    printf("\n");
  }

  return 0;
}