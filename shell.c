#include <stdio.h> // Importing Standard IO Header
#include <sys/types.h> // Defines many custom data types, one we are using is pid_t for process ID
#include <sys/wait.h> // Custom Functions and types for process management, we are using waitpid to await changes in process
#include <unistd.h> // UNIX API access
#include <string.h> // String Manipulation
#include <stdlib.h> // Exit Function

// Setting Max Input Characters
#define MAX_INPUT_CHARACTERS 100

// Main Function
int main(void) {
  while(1) {
    //Take Character Input
    char input[MAX_INPUT_CHARACTERS];

    printf("Shell Simulation in C \n");
    if (fgets(input, sizeof(input), stdin) == NULL) {
      // Handle input error or EOF
      break;
    }

    // Remove newline character
    if (input[strlen(input) - 1] == '\n') {
      input[strlen(input) - 1] = '\0';
    }

    char *token = strtok(input, " ");
    char *command = token; //First token is the command

    char *args[20];

    int i = 0;

    while(token != NULL) {
      token = strtok(NULL, " ");
      args[i++] = token;
      // Every token is an argument
    }

    args[i] = NULL;

    pid_t pid = fork(); // Create the process

    if(pid == 0) {
      if (execvp(command, args) == -1) {
        perror("Error executing command");
        exit(EXIT_FAILURE);
      }
    } else if(pid > 0) {
      // Process is a parent process
      wait(NULL);
    } else {
      perror("Fork Failure");
    }

    if (strcmp(command, "exit") == 0) {
      break;  // Exit the loop and end the shell
    }
  }
}