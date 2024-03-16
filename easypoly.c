#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
  int degree;
  int coeff;
} TERM;

int main(void)
{
  TERM poly1[10];
  TERM poly2[10];
  TERM resultpoly[10];

  int resultcounter = 0;

  poly1[0].coeff = 3;
  poly1[0].degree = 2;
  poly1[1].coeff = 2;
  poly1[1].degree = 1;
  poly1[2].coeff = 3;
  poly1[2].degree = 0;
  poly2[0].coeff = 3;
  poly2[0].degree = 2;
  poly2[1].coeff = 2;
  poly2[1].degree = 1;
  poly2[2].coeff = 3;
  poly2[2].degree = 0;

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (poly2[j].degree == poly1[i].degree)
      {
        resultpoly[resultcounter].degree = poly1[i].degree;
        resultpoly[resultcounter].coeff = poly1[i].coeff + poly2[j].coeff;
        resultcounter++;
      }
    }
  }
  for (int i = 0; i < 3; i++)
  {
    if (i == 2)
    {
      printf(" %dx^%d \n", resultpoly[i].coeff, resultpoly[i].degree);
    }
    else
    {
      printf(" %dx^%d +", resultpoly[i].coeff, resultpoly[i].degree);
    }
  }
}