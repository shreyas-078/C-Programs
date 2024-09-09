#include <stdio.h>
int b[100];
int a[100];

void merge(int l, int m, int h)
{
  int i = l, j = m + 1, k = l;
  while (i <= m && j <= h)
  {
    if (a[i] < a[j])
    {
      b[k] = a[i];
      i++;
      k++;
    }
    else
    {
      b[k] = a[j];
      j++;
      k++;
    }
  }
  while (i <= m)
  {
    b[k] = a[i];
    k++;
    i++;
  }
  while (j <= h)
  {
    b[k] = a[j];
    k++;
    j++;
  }
  for (i = l; i <= h; i++)
  {
    a[i] = b[i];
  }
}

void merge_sort(int l, int h)
{
  if (l < h)
  {
    int m = (l + h) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, h);
    merge(l, m, h);
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
  merge_sort(l, h);
  printf("The array elements after sort\n");
  for (i = 0; i < n; i++)
  {
    printf("%d", a[i]);
  }
}