#include<stdio.h>
int main()
{
    int arr[4]={10,20,30,50};
    printf("Element in reverse order is given below\n");
    for(int i=4;i>=0;i--)
    {
        printf("%d\n",arr[i]);
    }
}