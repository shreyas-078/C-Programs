// To find substring without using string functions

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ip[50], substr[10];
    int i;
    printf("Enter the string: \n");
    scanf("%s", ip);
    printf("Enter the substring: \n");
    scanf("%s", substr);

    int t = strlen(substr);
    int iplen = strlen(ip);

    int counter = 0;

    for (i = 0; i < iplen; i++)
    {
        counter = 0;
        if (ip[i] == substr[0])
        {
            for (int j = 0; j < t; j++)
            {
                if (ip[i + j] == substr[j])
                    counter++;
                else
                    break;
            }
            if (counter == t)
            {
                printf("Substsring exists \n");
                exit(0);
            }
        }
    }
    printf("Given substring does not exist \n");
}
