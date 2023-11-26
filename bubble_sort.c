#include <stdio.h>

int main(void)
{
    int a[10],i,j,temp,n;

    //Reading array
    printf("Enter the Size of array\n");
    scanf("%d", &n);
    printf("Enter Elements of the Array\n");
    for(i=0; i<n; i++)
    scanf("%d", &a[i]);

    printf("Before sorting\n");
    for(i=0; i<n; i++)
    printf("%d", a[i]);

    //Sorting Starts
    for(i=0; i<n ;i++) {
        for(j=0; j<n-i-1; j++) {
            if(a[j]>a[j+1]) {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("After Sorting\n");
    for(i=0; i<n; i++)
    printf("%d\n", a[i]);
}