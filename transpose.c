#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
  int col;
  int row;
  int value;
} TERM;

void transpose(TERM *a[], TERM *b[])
{
  int n = 3;
  printf("%d \n", n);
  for (int i = 0; i < n; i++)
  {
    // swap the values of a[i]->col and a[i]->row
    int temp = a[i]->col;
    a[i]->col = a[i]->row;
    a[i]->row = temp;

    // copy the pointer from a to b
    b[i] = a[i];
  }
}

int main(void)
{
  TERM *a[3];
  TERM *b[3];
  // allocate memory for the pointers
  for (int i = 0; i < 3; i++)
  {
    a[i] = malloc(sizeof(TERM));
    b[i] = malloc(sizeof(TERM));
  }
  // assign values to the matrix
  a[0]->col = 2;
  a[0]->row = 2;
  a[0]->value = 3;
  a[1]->col = 1;
  a[1]->row = 1;
  a[1]->value = 3;
  a[2]->col = 0;
  a[2]->row = 0;
  a[2]->value = 3;
  // store the number of non-zero elements in the value field
  a[0]->value = a[1]->value = a[2]->value = 3;
  transpose(a, b);
  // print the transposed matrix
  for (int i = 0; i < 3; i++)
  {
    int k = 0; // index of the non-zero element
    for (int j = 0; j < 3; j++)
    {
      if (k < b[i]->value && b[i]->row == j)
      {
        printf("%d\t", b[i]->col);
        k++;
      }
      else
      {
        printf("%d \t", 0);
      }
    }
    printf("\n");
  }
  // free the memory
  for (int i = 0; i < 3; i++)
  {
    free(a[i]);
    free(b[i]);
  }
}
