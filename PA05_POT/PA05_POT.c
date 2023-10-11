#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getUnitsNumber();

int main() {
  int testNo, iteration;

  scanf("%d", &testNo);
  for (iteration = 0; iteration < testNo; iteration++) {
    getUnitsNumber();
  }
  return 0;
}

void getUnitsNumber() {
  int number, base, power;
  int values[9][4] = {{1}, {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6}, {5}, {6}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1}};

  scanf("%d %d", &number, &power);

  base = number % 10;

  if (power == 0) {
    printf("1\n");
  } else if (base == 0) {
    printf("0\n");
  } else if (base == 1 || base == 5 || base == 6) {
    printf("%d\n", values[base - 1][0]);
  } else {
    div_t modulo;

    if (base == 4 || base == 9) {
      modulo = div(power, 2);
      if (modulo.rem == 0) { 
        printf("%d\n", values[base - 1][1]);
      } else {
        printf("%d\n", values[base - 1][0]);
      }
    } else {
      div_t even, odd;
      modulo = div(power, 2);
      if (modulo.rem == 0) {
        even = div(power, 4);
        if (even.rem == 0) {
          printf("%d\n", values[base - 1][3]);
        } else {
          printf("%d\n", values[base - 1][1]);
        }
      } else {
        odd = div((power - 1), 4);
        if (odd.rem == 0) {
          printf("%d\n", values[base - 1][0]);
        } else {
          printf("%d\n", values[base - 1][2]);
        }
      }
    }
  }
}