#include <stdio.h>
#include <stdlib.h>

struct DAY
{
  char dayname;
  int date;
  char activity;
};

void create(struct DAY *day)
{
  day->dayname = (char *)malloc(sizeof(char) * 20);
  day->activity = (char *)malloc(sizeof(char) * 50);
  printf("Enter the name of the day ");
  scanf("%s", day->dayname);
  printf("Enter the date for the day");
  scanf("%d", &day->date);
  printf("Enter the activity for the day");
  scanf("%s", day->activity);
}

void read(struct DAY *calendar, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("Enter details for day %d", i + 1);
    create(&calendar[i]);
  }
}

void display(struct DAY *calendar, int size)
{
  printf("Activity Details");
  printf("_");
  printf("Day\t\tName of the day\tDate\tActivity\n");
  printf("__");
  for (int i = 0; i < size; i++)
  {
    printf("%d\t\t%c\t\t%d\t%s\n", i + 1, calendar[i].dayname, calendar[i].date, calendar[i].activity);
  }
}

void freememory(struct DAY *calendar, int size)
{
  for (int i = 0; i < size; i++)
  {
    free(calendar[i].dayname);
    free(calendar[i].activity);
  }
}

int main()
{
  int size;
  printf("Enter the number of days in the week");
  scanf("%d", &size);
  struct DAY *calendar = (struct DAY *)malloc(sizeof(struct DAY) * size);
  if (calendar == NULL)
  {
    printf("Memory allocation failed");
    return 1;
  }
  read(calendar, size);
  display(calendar, size);
  freememory(calendar, size);
  free(calendar);
  return 0;
}