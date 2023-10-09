#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getArray();

int main() {

  char userInput;
  char array[25];
  char *inputArray = array;
  int len = 0, size = 0;

  while ((userInput = getchar()) != '\n' && userInput != EOF && len < sizeof(array) - 1) {
    inputArray[len] = userInput;
    len++;
    if (userInput == ' ') {
      size++;
    }
  }
  inputArray[len] = '\0';

  int newArray[size];
  int position = 0;

  while (*inputArray) {
    if (isdigit(*inputArray)) {
      int number = strtol(inputArray, &inputArray, 10);
      newArray[position] = number;
      ++position;
    } else {
      inputArray++;
    }
  }

  printf("%d", ((newArray[0] * newArray[1]) + (newArray[2] * newArray[3])));
  return 0;
}