#include<stdio.h>
int main()
{
    int arr[80],n,sum=0;
    printf("How many elements you want to add\n");
    scanf("%d",&n);
    printf("Now Enter %d number one by one\n ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum=sum+arr[i];
    }
    printf("Total sum=%d",sum);
}