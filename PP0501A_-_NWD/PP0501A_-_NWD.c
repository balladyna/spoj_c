#include <stdio.h>
#include <stdlib.h>

int nwd();

int main() {
  int test_no, number;

  scanf("%d", &test_no);

  for (number = 0; number < test_no;) {
    printf("%d\n", nwd());
    number++;
  }
  return 0;
}

int nwd() {
  double test_no_1, test_no_2;
  div_t modulo;

  scanf("%le %le", &test_no_1, &test_no_2);

  while (test_no_2 != 0) {
    modulo = div(test_no_1, test_no_2);
    test_no_1 = test_no_2;
    test_no_2 = modulo.rem;
  }
  return test_no_1;
}
