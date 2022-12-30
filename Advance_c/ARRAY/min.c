#include<stdio.h>
int main()
{
    int a[50],n,min;
    printf("Enter how many number you want to store\n");
    scanf("%d",&n);
    printf("now Enter %d number one by one\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    min=a[0];
    for(int j=0;j<n;j++)
    {
        if(min>a[j])
        min=a[j];
    }
    printf("Minimum value=%d",min);
}