#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

char stk[10];
int top = -1;

void push(int element)
{
  stk[++top] = element;
}

int pop()
{
  return stk[top--];
}

int eval(char postfix[])
{
  int i = 0;
  while (postfix[i] != '\0')
  {
    if (isdigit(postfix[i]))
    {
      push((postfix[i] - '0'));
    }
    else
    {
      int op2 = pop();
      int op1 = pop();
      switch (postfix[i])
      {
      case '+':
        push(op1 + op2);
        break;
      case '-':
        push(op1 - op2);
        break;
      case '*':
        push(op1 * op2);
        break;
      case '/':
        push(op1 / op2);
        break;
      case '^':
        push(pow(op1, op2));
      default:
        break;
      }
    }
    i++;
  }
  int result = pop();
  return result;
}

int main()
{
  char postfix[30];
  printf("Enter postix expression: \n");
  scanf("%s", postfix);
  int result = eval(postfix);
  printf("The Evaluation of expression is: %d \n", result);
  return 0;
}