#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef struct day
{
  char *dayname;
  int date;
  char *activity;
} DAY;

void create(DAY *, int);
void display(DAY *, int);
void freecalendar(DAY *, int);

int main()
{
  int n;
  printf("Enter number of days:\n");
  scanf("%d", &n);
  DAY *week = (DAY *)malloc(MAX * sizeof(DAY));
  create(week, n);
  display(week, n);
  freecalendar(week, n);
  return 0;
}

void create(DAY *week, int n)
{
  for (int i = 0; i < n; i++)
  {
    week[i].dayname = (char *)malloc(20 * sizeof(char));
    week[i].activity = (char *)malloc(50 * sizeof(char));
    printf("Enter the day Name \n");
    scanf("%s", week[i].dayname);
    printf("Enter date \n");
    scanf("%d", &week[i].date);
    printf("Enter activity \n");
    scanf("%s", week[i].activity);
  }
}

void display(DAY *week, int n)
{
  printf("Day Number \t Day Name \t Date \t Activity \n");
  for (int i = 0; i < n; i++)
  {
    printf("%d \t %s \t %d \t %s \n", i, week[i].dayname, week[i].date, week[i].activity);
  }
}

void freecalendar(DAY *week, int n)
{
  for (int i = 0; i < n; i++)
  {
    free(week[i].dayname);
    free(week[i].activity);
  }
  free(week);
}