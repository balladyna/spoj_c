#include <stdio.h>

int velocity();

int main() {
  int test_no, number;

  scanf("%d\n", &test_no);
  for (number = 0; number < test_no;) {
    printf("%d\n", velocity());
    number++;
  }
  return 0;
}

int velocity() {
  int v1, v2, velocity;

  scanf("%d %d", &v1, &v2);
  velocity = 2 * v1 * v2 / (v1 + v2);
  return velocity;
}
