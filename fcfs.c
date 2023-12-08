#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 20

int main() {
  int n, *at, *bt, *wt, *tt;

  printf("Enter the number of Processes (max 20): \n");
  scanf("%d", &n);

  if(n > MAX_PROCESS || n < 1) {
    printf("Invalid Number of processes");
    exit(1);
  }

  at = (int *)malloc(n*sizeof(int));
  bt = (int *)malloc(n*sizeof(int));
  wt = (int *)malloc(n*sizeof(int));
  tt = (int *)malloc(n*sizeof(int));

  for(int i=0; i<n; i++) {
    printf("Enter the arrival time of process %d: \n", i+1);
    scanf("%d", at + i);
    printf("Enter the burst time of process %d: \n", i+1);
    scanf("%d", bt + i);
  }

  int totalprocessbursttime=0;

  for(int i=0; i<n; i++) {
    totalprocessbursttime += *(bt+i);
    *(wt+i) = totalprocessbursttime- *(bt+i)-*(at+i);
    *(tt+i) = *(wt+i)+*(bt+i);  
  }

  float sumwaittime=0;
  float sumturaroundtime=0;

  printf("PROCESS \t ARRIVAL TIME \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
  for(int i=0; i<n; i++) {
    sumturaroundtime+=*(tt+i);
    sumwaittime+=*(wt+i);
    printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \n", i+1, *(at+i), *(bt+i), *(wt+i), *(tt +i));
  }

  printf("Average Wait time = %fs \nAverage Turnaround time = %fs \n", sumwaittime/n, sumturaroundtime/n);

  return 0;

} 