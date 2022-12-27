#include<stdio.h>
int main()
{
    int arr[3],n,sum=0;
    
    printf("Now Enter 3 number one by one\n ",n);
    for(int i=0;i<4;i++)
    {
        scanf("%d",&arr[i]);
        sum=sum+arr[i];
    }
    printf("Total sum=%d",sum);
}