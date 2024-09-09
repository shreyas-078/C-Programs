#include <stdio.h>

int a[100];

int partition(int l, int h)
{
  int i = l + 1, j = h, pivot = a[l], temp;
  do
  {
    while (pivot >= a[i] && i <= h)
    {
      i++;
    }
    while (pivot < a[j])
    {
      j--;
    }
    if (i < j)
    {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  } while (i < j);

  temp = a[l];
  a[l] = a[j];
  a[j] = temp;

  return j;
}

void quick_sort(int l, int h)
{
  if (l < h)
  {
    int part = partition(l, h);
    quick_sort(l, part - 1);
    quick_sort(part + 1, h);
  }
}

int main(void)
{
  int l = 0, h, n, i;
  printf("Enter the number of elements \n");
  scanf("%d", &n);
  h = n - 1;
  printf("Enter the array elements \n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  quick_sort(l, h);
  printf("The array elements after sort\n");
  for (i = 0; i < n; i++)
  {
    printf("%d\n", a[i]);
  }
}
