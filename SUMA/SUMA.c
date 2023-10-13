#include <stdio.h>

int main() {
  int userNumber;
  int sum = 0;

  while (~scanf("%d", &userNumber)) {
    printf("%d\n", (sum += userNumber));
  }
  return 0;
}