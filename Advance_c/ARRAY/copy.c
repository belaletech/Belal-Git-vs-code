#include<stdio.h>
int main()
{
    int a[5]={5,20,40,30,60};
    int b[5];
    printf("Enter array is given Below\n");
    for(int i=0;i<=4;i++)
    {
        printf("%d ",a[i]);
        b[i]=a[i];
    }
    printf("\n After copy second array is given below\n");
    for(int j=0;j<=4;j++)
    {
        printf("%d ",a[j]);
    }
}