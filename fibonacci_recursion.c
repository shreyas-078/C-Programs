#include<stdio.h>

int fibonacci (int n)

{

if(n==0)
return 0;
else if (n == 1)
return 1;
else
return (fibonacci (n-1)+fibonacci (n-2));

}

int main(void)
{
int n, i, result;
printf("Enter a value for n\n");

scanf("%d", &n);

printf("The Fibonacci series is: \n");

for ( i =0; i < n ; i ++) {
    result = fibonacci(i);
    printf("%d\n", result);
}
}