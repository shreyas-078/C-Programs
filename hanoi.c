#include <stdio.h>
#include <stdlib.h>

void tower(int n, char src, char temp, char dest)
{
  if (n == 0)
  {
    return;
  }
  tower(n - 1, src, dest, temp);
  printf("Move disc %d from %c to %c \n", n, src, dest);
  tower(n - 1, temp, src, dest);
}

int main(void)
{
  int n = 3;
  tower(n, 'A', 'B', 'C');
}