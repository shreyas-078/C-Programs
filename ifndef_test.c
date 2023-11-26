#include <stdio.h>
#include <stdlib.h>

#define MAX_AGE 70

#ifndef MAX_AGE
#define MAX_AGE 65
#endif

int main(void) {
  int age;

  printf("Enter your age \n");
  scanf("%d", &age);

  if(age < 0) {
    printf("Enter a valid Age. \n");
    exit(0);
  }

  if(age < MAX_AGE) {
    printf("Not a senior citizen \n");
  } else {
    printf("Senior Citizen \n");
  }
}

