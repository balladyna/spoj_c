#include <stdio.h>
#include <stdlib.h>


int main() {
  int testNo, iteration;
  unsigned long long factorial;
  char array[10][4] = {"0 1","0 2","0 6","2 4","2 0","2 0","4 0","2 0","8 0"};

  scanf("%d", &testNo);

  for (iteration = 0; iteration < testNo; iteration++) {
    scanf("%lld", &factorial);
  
    if (factorial >= 10) {
      printf("0 0\n");
    } else {
      if (factorial == 0)
        printf("%s \n", array[factorial]);
      else
      	printf("%s \n", array[factorial-1]);
    }
  }
  return 0;
}
