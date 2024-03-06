#include <stdio.h>
#include <string.h>

int stkpre(char symbol)
{
  switch (symbol)
  {
  case '+':
  case '-':
    return 2;
  case '*':
  case '/':
    return 4;
  case '^':
  case '$':
    return 5;
  case '(':
    return 0;
  case '#':
    return -1;
  default:
    return 8;
  }
}

int inpre(char symbol)
{
  switch (symbol)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 3;
  case '^':
  case '$':
    return 6;
  case '(':
    return 9;
  case ')':
    return 0;
  default:
    return 7;
  }
}

void infix_postfix(char infix[], char postfix[])
{
  int i = 0, j = 0, top = -1;
  char symbol, stack[30];
  stack[++top] = '#';
  for (i = 0; i < strlen(infix); i++)
  {
    symbol = infix[i];
    while (inpre(symbol) < stkpre(stack[top]))
    {
      postfix[j] = stack[top--];
      j++;
    }
    if (inpre(symbol) != stkpre(stack[top]))
    {
      stack[++top] = symbol;
    }
    else
    {
      top--;
    }
  }
  while (stack[top] != '#')
  {
    postfix[j++] = stack[top--];
  }
  postfix[j] = '\0';
}

int main()
{
  char infix[20], postfix[20];
  printf("Enter a valid infix expression\n");
  gets(infix);
  infix_postfix(infix, postfix);
  printf("The postfix expression is: %s \n", postfix);
  return 0;
}
