#include <stdio.h>
#include <math.h>

const char* is_prime();

int main()
{
  int a, n;


  scanf("%d\n", &n);

  for (a = 0; a < n; a++)
  {
    printf(is_prime());
  }
  return 0;
}

const char*  is_prime()
{
  int i, b, z;

  b = 0;

  scanf("%d", &z);
  if (z > 1)
    {
      if (z == 2)
      {
        return "TAK\n";
      }
      for (i = 2; i < (sqrt(z) + 1);)
      {
        if (z % i == 0)
        {
          b++;
          return "NIE\n";
        }
        i++;
      }
      if (b == 0)
        {
          return "TAK\n";
        }
    }
  else
  {
    return "NIE\n";
  }
  return NULL;
}
