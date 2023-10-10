#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nwd(int numberOne, int numberTwo);

int main() {
  int testNo, iteration;

  scanf("%d\n", &testNo);

  for (iteration = 0; iteration < testNo; iteration++) {
    int numberOne, numberTwo;

    scanf("%d %d", &numberOne, &numberTwo);

    printf("%d\n", ((numberOne * numberTwo) / nwd(numberOne, numberTwo)));
  }
  return 0;
}

int nwd(int numberOne, int numberTwo) {
  div_t modulo;

  while (numberTwo != 0) {
    modulo = div(numberOne, numberTwo);
    numberOne = numberTwo;
    numberTwo = modulo.rem;
  }
  return numberOne;
}
