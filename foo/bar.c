#include <stdio.h>

int main() {
  int a = 6, b = 10, c = 15;

  int *x = &c, *y = &a, *z = &b;

  int **r = &x, **s = &z, **t = &y;

  int **tmp;

  tmp = r;
  r = s;
  s = tmp;
  
  return 0;
}