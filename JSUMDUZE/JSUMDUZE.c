#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int userInput;
  

  scanf("%d", &userInput);

  getchar();

  for (int iteration = 0; iteration < userInput; iteration++) {
    char userNumbers;
    char inputArray[2001];
    int len = 0;
    int twoArrays[2][1000];
    int position = 0, length = 0;

    while ((userNumbers = getchar()) != EOF && userNumbers != '\n' && len < sizeof(inputArray) - 1) {
      inputArray[len] = userNumbers;
      len++;
    }
    inputArray[len] = '\0';

    int index = 0, iter = 0;

    while (inputArray[iter] != '\0') {
      if (isdigit(inputArray[iter])) {
        twoArrays[index][position] = inputArray[iter] - '0';
        position++;
      } else if (isspace(inputArray[iter])) {
        length = position;
        index++;
        position = 0;
      }
      iter++;
    }

    int sumArray[2000];
    int tens = 0, sumIndex = 0;

    while (length > 0 || position > 0 || tens > 0) {
      int digitOne = 0, digitTwo = 0, newDigit;

      if (length > 0) {
        digitOne = twoArrays[0][length - 1];
        length--;
      }
      if (position > 0) {
        digitTwo = twoArrays[1][position - 1];
        position--;
      }
      newDigit = digitOne + digitTwo + tens;
      if (newDigit < 10) {
        sumArray[sumIndex] = newDigit;
        tens = 0;
      } else {
        sumArray[sumIndex] = newDigit % 10;
        tens = newDigit / 10;
      }
      sumIndex++;
    }

    int nonZero = 0;

    for (int i = sumIndex - 1; i >= 0; i--) {
      if (sumArray[i] != 0) {
        nonZero = 1;
      }
      if (nonZero) {
        printf("%d", sumArray[i]);
      }
    }
    if (!nonZero) {
      printf("0");
    }
    printf("\n");
  }
  return 0;
}