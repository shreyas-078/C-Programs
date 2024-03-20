#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct term
{
  int px, py, pz, cf;
  struct term *next;
} TERM;

void display_poly(TERM *head)
{
  TERM *current = head;
  do
  {
    printf("%dx^%dy^%dz^%d", current->cf, current->px, current->py, current->pz);
    if (current->next != head)
    {
      printf(" + ");
    }
    current = current->next;
  } while (current != head);
  printf("\n");
}

void eval_poly(TERM *polyhead)
{
  TERM *current = polyhead;
  int x, y, z, result = 0;
  printf("Enter x value: \n");
  scanf("%d", &x);
  printf("Enter y value: \n");
  scanf("%d", &y);
  printf("Enter z value: \n");
  scanf("%d", &z);
  do
  {
    result += current->cf * pow(x, current->px) * pow(y, current->py) * pow(z, current->pz);
    current = current->next;
  } while (current != polyhead);
  printf("Evaluation of Polynomial is: %d \n", result);
}

void input_poly(TERM **head)
{
  int flaginput = 1;
  do
  {
    TERM *newterm = (TERM *)malloc(sizeof(TERM));
    TERM *current = *head;
    printf("Enter coeff \n");
    scanf("%d", &(newterm->cf));
    printf("Enter the X pow \n");
    scanf("%d", &(newterm->px));
    printf("Enter the Y pow \n");
    scanf("%d", &(newterm->py));
    printf("Enter the Z pow \n");
    scanf("%d", &(newterm->pz));
    if (*head == NULL)
    {
      *head = newterm;
      newterm->next = *head;
    }
    else
    {
      while (current->next != *head)
      {
        current = current->next;
      }
      current->next = newterm;
      newterm->next = *head;
    }
    printf("Do you want to enter more terms (1 for YES / 0 for NO) \n");
    scanf("%d", &flaginput);
  } while (flaginput == 1);
  printf("The polynomial is: \n");
  display_poly(*head);
}

void add_poly(TERM *poly1, TERM *poly2, TERM **result)
{
  TERM *current = poly1;
  do
  {
    TERM *newterm = (TERM *)malloc(sizeof(TERM));
    newterm->cf = current->cf;
    newterm->px = current->px;
    newterm->py = current->py;
    newterm->pz = current->pz;
    newterm->next = NULL;

    if (*result == NULL)
    {
      *result = newterm;
      (*result)->next = *result;
    }
    else
    {
      TERM *last = *result;
      do
      {
        last = last->next;
      } while (last != *result);
      last->next = newterm;
      newterm->next = *result;
    }
    current = current->next;
  } while (current != poly1);

  TERM *current2 = poly2;
  do
  {
    TERM *currentresult = *result;
    int found = 0;
    do
    {
      if (current2->px == currentresult->px && current2->py == currentresult->py && current2->pz == currentresult->pz)
      {
        currentresult->cf += current2->cf;
        found = 1;
        break;
      }
      currentresult = currentresult->next;
    } while (currentresult != *result);
    if (found == 0)
    {
      TERM *notterm = (TERM *)malloc(sizeof(TERM));
      notterm->cf = current2->cf;
      notterm->px = current2->px;
      notterm->py = current2->py;
      notterm->pz = current2->pz;

      TERM *last = *result;
      while (last->next != *result)
      {
        last = last->next;
      }
      last->next = notterm;
      notterm->next = *result;
    }
    current2 = current2->next;
  } while (current2 != poly2);
}

int main()
{
  int ch;
  TERM *polyhead = NULL;
  TERM *poly1head = NULL;
  TERM *poly2head = NULL;
  TERM *resulthead = NULL;
  while (1)
  {
    printf("Enter choice \n");
    printf("1. Evaluate Polynomial \n");
    printf("2. Add 2 Polynomials \n");
    printf("3. Exit \n");
    printf("Enter your choice \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      polyhead = NULL;
      input_poly(&polyhead);
      eval_poly(polyhead);
      break;
    case 2:
      poly1head = NULL;
      poly2head = NULL;
      input_poly(&poly1head);
      input_poly(&poly2head);
      add_poly(poly1head, poly2head, &resulthead);
      printf("The polynomial after addition is: \n");
      display_poly(resulthead);
      break;
    case 3:
      exit(0);
    default:
      printf("Invalid Choice \n");
    }
  }
}
