#include<stdio.h>
int main()
{
    int first_array[50],second_array[50],third_array[50],n,i;
    printf("Enter the number of element\n");
    scanf("%d",&n);
    printf("Enter %d integer value of first array\n",n);
    for(i=0;i<n;i++)
    scanf("%d",&first_array[i]);
    printf("Now Enter %d integer value of array second\n",n);
    for(i=0;i<n;i++)
    scanf("%d",&second_array[i]);

    printf("\nAfter merging third array is given below\n");
    for(i=0;i<n*2;i++)
    {
        if(i<n)third_array[i]=first_array[i];
        else
        third_array[i]=second_array[i-n];
        printf("%d ",third_array[i]);
    }
}