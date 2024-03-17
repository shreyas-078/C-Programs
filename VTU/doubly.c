// ssn name dept designation salary phno

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int ssn;
  char name[20];
  char dept[10];
  char desig[10];
  int salary;
  char phno[10];
  struct node *prev;
  struct node *next;
} NODE;

NODE *head = NULL;

NODE *create_node()
{
  NODE *newnode = (NODE *)malloc(sizeof(NODE));
  printf("\nEnter SSN, Name, Dept, Designation, Sal, Ph.No\n");
  scanf("%d", &newnode->ssn);
  scanf("%s", newnode->name);
  scanf("%s", newnode->dept);
  scanf("%s", newnode->desig);
  scanf("%d", &newnode->salary);
  scanf("%s", newnode->phno);
  newnode->next = NULL;
  newnode->prev = NULL;
  return newnode;
}

void insert_front()
{
  NODE *newnode = create_node();

  if (head == NULL)
  {
    printf("Eneterd thisd");
    head = newnode;
  }
  else
  {
    newnode->next = head;
    newnode->prev = NULL;
    head = newnode;
  }
}

void insert_end()
{
  if (head == NULL)
  {
    insert_front();
    return;
  }
  NODE *current = head;
  NODE *newnode = create_node();
  while (current->next != NULL)
  {
    current = current->next;
  }
  newnode->next = NULL;
  current->next = newnode;
  newnode->prev = current;
}

void del_front()
{
  if (head == NULL)
  {
    printf("Empty \n");
    return;
  }
  head = head->next;
}

void del_end()
{
  NODE *current = head;
  while (current->next->next != NULL)
  {
    current = current->next;
  }
  current->next = NULL;
}

void display()
{
  if (head == NULL)
  {
    printf("Empty list! \n");
    return;
  }
  NODE *p = head;
  printf("\nSSN\tNAME\tDEPT\tDESINGATION\tSAL\t\tPh.NO. \n");
  while (p != NULL)
  {
    printf("\n%d\t%s\t%s\t%s\t\t%d\t\t%s", p->ssn, p->name, p->dept, p->desig, p->salary, p->phno);
    p = p->next;
  }
  printf("\n");
}

int main()
{

  int ch;
  while (1)
  {
    printf("1. Insert Front \n");
    printf("2. Insert End \n");
    printf("3. Delete Front \n");
    printf("4. Delete End \n");
    printf("5. Display \n");
    printf("6. Exit \n");
    printf("Enter your choice \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      insert_front();
      break;
    case 2:
      insert_end();
      break;
    case 3:
      del_front();
      break;
    case 4:
      del_end();
      break;
    case 5:
      display();
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid Choice! \n");
    }
  }
  return 0;
}