#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n, a[10], target, pos;
  printf("Enter number of elements \n");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("Enter element to insert \n");
  scanf("%d", &target);
  printf("Enter position to insert at \n");
  scanf("%d", &pos);

  for (int i = 0; i < n; i++)
  {
    if (i == pos)
    {
      for (int j = n; j >= pos; j--)
      {
        a[j + 1] = a[j];
      }
      a[pos] = target;
      n++;
    }
  }
  for (int i = 0; i < n; i++)
    printf("%d", a[i]);
  printf("\n");
}