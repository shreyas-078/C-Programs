#include <stdio.h>

int bitcount(int count, int num)
{
  count++;
  if (num == 1)
  {
    return count++;
  }
  return bitcount(count, num / 2);
}

int main(void)
{
  int num;
  int count = 0;
  printf("Enter the integer to check bits in binary representation\n");
  scanf("%d", &num);
  count = bitcount(count, num);
  printf("%d", count);
}
