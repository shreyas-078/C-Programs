#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Queue {
  int front, rear, size;
  int capacity;
  int *array;
};

typedef struct Queue Queue;

Queue* createqueue(int capacity) {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue -> capacity = capacity;
  queue -> front = queue -> size = 0;
  queue -> rear = capacity - 1;
  queue -> array = (int*)malloc(queue -> capacity * sizeof(int));
  return queue;
}

int isFull(Queue* queue) {
  return (queue -> size == queue -> capacity);
}

int isEmpty(Queue* queue) {
  return (queue -> size == 0);
}

void enqueue(Queue* queue, int item) {
  if(isFull(queue)) {
    printf("Queue is full \n");
    return;
  }
  queue -> rear = (queue -> rear + 1) % queue -> capacity;
  queue -> array[queue -> rear] = item;
  queue -> size += 1;
  printf("Enqueued %d to Queue \n", item);
}

int dequeue(Queue* queue) {
  if(isEmpty(queue)) {
    printf("Queue is empty \n");
    return INT_MIN;
  }
  int removedItem = queue -> array[queue -> front];
  queue -> front = (queue -> front + 1) % queue -> capacity;
  queue -> size -= 1;
  printf("%d dequeued from the queue \n", removedItem);
  return removedItem;
}

int front(Queue* queue) {
  if(isEmpty(queue)) {
    return INT_MIN;
  } 
  return queue -> array[queue -> front];
}

int rear(Queue* queue) {
  if(isEmpty(queue)) {
    return INT_MIN;
  }
  return queue -> array[queue -> rear];
}

void display(Queue* queue) {
  for(int i=(queue -> front); i<=(queue -> rear); i++) {
    printf("%d ", queue->array[i]);
  }
}

char* convertToUppercase(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = toupper(str[i]);
  }
  return str;
}

int main(void) {
  int n;
  printf("Enter capacity of queue: \n");
  scanf("%d", &n);
  Queue *queue = createqueue(n);
  printf("Enter operations: \n Examples: ENQUEUE, DEQUEUE, FRONT, REAR, ISMEMPTY, ISFULL & EXIT\n");
  while(1) {
    char operation[10];
    scanf("%9s", operation);
    char uppercaseOperation[10];
    strcpy(uppercaseOperation, convertToUppercase(operation));
    if(strcmp(uppercaseOperation, "EXIT") == 0) {
      break;
    } else if(strcmp(uppercaseOperation, "ENQUEUE") == 0) {
      int enqueueElement;
      printf("Enter element to Enqueue: \n");
      scanf("%d", &enqueueElement);
      enqueue(queue, enqueueElement);
    } else if(strcmp(uppercaseOperation, "DEQUEUE") == 0) {
      dequeue(queue);
    } else if(strcmp(uppercaseOperation, "FRONT") == 0) {
      printf("%d \n" ,front(queue));
    } else if(strcmp(uppercaseOperation, "REAR") == 0) {
      printf("%d \n", rear(queue));
    } else if(strcmp(uppercaseOperation, "ISEMPTY") == 0) {
      printf("%d \n", isEmpty(queue));
    } else if(strcmp(uppercaseOperation, "ISFULL") == 0) {
      printf("%d \n", isFull(queue));
    } else if(strcmp(uppercaseOperation, "DISPLAY") == 0) {
      display(queue);
      printf("\n");
    } else {
      printf("Invalid Operation \n");
    }
  }
}




