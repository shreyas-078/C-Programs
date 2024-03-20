#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace_pattern(char sentence[30], char pattern[10], char replace[10], char final[30])
{
  int i, j, k, m, c, flag;
  i = j = m = k = c = flag = 0;
  while (sentence[c] != '\0')
  {
    if (sentence[m] == pattern[i])
    {
      i++;
      m++;
      if (pattern[i] == '\0')
      {
        flag = 1;
        for (k = 0; replace[k] != '\0'; k++, j++)
        {
          final[j] = replace[k];
        }
        c = m;
        i = 0;
      }
    }
    else
    {
      c++;
      j++;
      m = c;
      i = 0;
    }
  }
  final[j] = '\0';
  return flag;
}

int main()
{
  char sentence[30], pattern[10], replace[10], final[30];
  printf("Enter the sentence: \n");
  gets(sentence);
  printf("Enter the pattern string: \n");
  gets(pattern);
  printf("Enter the replacement string: \n");
  gets(replace);
  int flag = replace_pattern(sentence, pattern, replace, final);
  if (flag == 1)
  {
    printf("Pattern Found! \n The String after replacement is: \n %s", final);
  }
  else
  {
    printf("Pattern not found! \n");
  }
  return 0;
}