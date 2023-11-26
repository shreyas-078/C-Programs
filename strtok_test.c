#include <string.h>
#include <stdio.h>

int main(void) {
  char str[100];
  const char splitter[] = " ";

  printf("Enter a string \n");
  fgets(str, sizeof(str), stdin);

  char *token = strtok(str, splitter);

  while(token != NULL) {
    printf("Token: %s\n", token);

    token = strtok(NULL, splitter);
  }
}