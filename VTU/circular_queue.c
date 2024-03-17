#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int master_queue[10];
int front = 0;
int rear = -1;
int count = 0;

void enqueue(int element)
{
  rear = (rear + 1) % MAX;
  master_queue[rear] = element;
  count++;
}

void dequeue()
{
  front = (front + 1) % MAX;
  count--;
}

void display()
{
  int temp = 0;
  if (count == 0)
  {
    printf("Queue is empty! \n");
    return;
  }
  for (int i = front; temp < count; i = (i + 1) % MAX, temp++)
  {
    printf("%d ", master_queue[i]);
  }
  printf("\n");
}

int main()
{
  int ch;
  int ele;
  while (1)
  {
    printf("1. Enqueue \n");
    printf("2. Dequeue \n");
    printf("3. Display \n");
    printf("4. Exit \n");
    printf("Enter your choice \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter element to enqueue: \n");
      scanf("%d", &ele);
      if (count >= MAX)
      {
        printf("Queue is full! Cannot insert. \n");
      }
      else
      {
        enqueue(ele);
      }
      break;

    case 2:
      if (count == 0)
      {
        printf("Queue is empty! \n");
      }
      else
      {
        dequeue();
      }
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice! \n");
    }
  }
  return 0;
}
