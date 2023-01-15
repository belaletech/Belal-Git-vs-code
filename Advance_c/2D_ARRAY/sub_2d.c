#include<stdio.h>
void main()
{
    int arr_first[2][2]={{5,9},{8,10}};
    int arr_second[2][2]={{4,3},{5,7}};
    int arr_third[2][2];
    int i,j;
    printf("First array is given below\n");
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            printf("%d ",arr_first[i][j]);
        }
        printf("\n");
    }
    printf("Second array is given below\n");
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            printf("%d ",arr_second[i][j]);
        }
        printf("\n");
    }
    printf("Subtraction of first and second array is given below\n");
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            arr_third[i][j]=arr_first[i][j]-arr_second[i][j];
            printf("%d ",arr_third[i][j]);
        }
        printf("\n");
    }
}