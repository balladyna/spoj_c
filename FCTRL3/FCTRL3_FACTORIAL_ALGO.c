#include <stdio.h>
#include <stdlib.h>

int * get_factorial(int array[]);

int main() {
  int test_no, iteration, array[2];
  
  scanf("%d", &test_no);


  for (iteration = 0; iteration < test_no;) {
    get_factorial(array);
    printf("%d %d\n", array[1], array[0]);
    iteration++;
  }
  return 0;
}

int * get_factorial(int array[]) {
  int iteration;
  int result = 1, factorial;

  scanf("%d", &factorial);
  if (factorial >= 10) {
    array[0] = 0;
    array[1] = 0;
    return array;
  }
  for (iteration = 1; iteration <= factorial; ++iteration) {
    result *= iteration;
  }
  for (iteration = 0; iteration < 2; iteration++, result /= 10) {
    array[iteration] = result % 10;
  }
  return array;
}
