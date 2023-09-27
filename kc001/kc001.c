#include <stdio.h>

int main()
{
  int a, b, c, d;

  scanf("%d %d %d", &a, &b, &c);

  if ((a <= 100) && (b <= 100) && (c <= 100))
  {
    d = a + b + c;
    printf("%d\n", d);
  }
  return 0;
}