#include<stdio.h>
int main()
{
    int a[50],n,max;
    printf("Enter how many element you want to store\n");
    scanf("%d",&n);
    printf("Enter %d numbers one by one\n",n);
    for (int i = 0; i < n; i++)
    scanf("%d",&a[i]);
    max=a[0];
    for (int j = 0; j < n; j++)
    {
        if(max<a[j])
        max=a[j];
    }
    printf("Maximum value=%d",max);
    
    
}