#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *head_ref = NULL;
int currentNodes = 0;

void insert_beggining(int element)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (head_ref == NULL)
  {
    new_node->data = element;
    new_node->next = NULL;
    new_node->prev = NULL;
    head_ref = new_node;
    currentNodes++;
    return;
  }
  new_node->data = element;
  head_ref->prev = new_node;
  new_node->prev = NULL;
  new_node->next = head_ref;
  head_ref = new_node;
  currentNodes++;
}

void display_list()
{
  struct Node *current = head_ref;
  while (current != NULL)
  {
    printf("%d\n", current->data);
    current = current->next;
  }
}

void insert_end(int element)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (head_ref == NULL)
  {
    new_node->data = element;
    head_ref = new_node;
    new_node->next = NULL;
    new_node->prev = NULL;
    currentNodes++;
    return;
  }
  struct Node *current = head_ref;
  while (current->next != NULL)
  {
    current = current->next;
  }
  new_node->next = NULL;
  new_node->data = element;
  current->next = new_node;
  new_node->prev = current;
  currentNodes++;
}

void insert_middle(int position, int element)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  struct Node *current = head_ref;
  if (head_ref == NULL)
  {
    printf("%s", "Ning yak bek insertion\n");
    return;
  }
  int counter = 0;

  if (position > currentNodes)
  {
    printf("%s", "Ning yak bek insertion\n");
    return;
  }
  while (counter != position - 1)
  {
    current = current->next;
    counter++;
  }
  new_node->data = element;
  new_node->next = current->next;
  new_node->prev = current;
  current->next = new_node;
}

void delete_beginning()
{
  if (head_ref == NULL)
  {
    printf("%s", "Ning yak bek deletion.\n");
    return;
  }
  head_ref = head_ref->next;
  head_ref->prev = NULL;
}

void delete_end()
{
  struct Node *current = head_ref;
  if (head_ref == NULL)
  {
    printf("%s", "Ning yak bek deletion.\n");
    return;
  }
  while (current->next->next != NULL)
  {
    current = current->next;
  }
  current->next = NULL;
}

void delete_middle(int position)
{
  struct Node *next = (struct Node *)malloc(sizeof(struct Node));
  struct Node *current = head_ref;
  int counter = -1;
  while (counter != position - 1)
  {
    next = current->next->next;
    current = current->next;
    counter++;
  }
  next->prev = current->prev;
  current->next = next->next;
}

int main(void)
{
  insert_beggining(30);
  insert_end(20);
  insert_middle(1, 111);
  insert_end(40);
  insert_end(60);
  delete_middle(1);
  display_list();
}