#include<stdio.h>
void main()
{
    int arr_first[3][3]={{3,4,5},{5,9,6},{6,7,8}};
    int arr_second[3][3]={{2,4,6},{8,9,7},{8,9,6}};
    int arr_third[3][3];
    int i,j;
    printf("Your first array is given below\n");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
        printf("%d ",arr_first[i][j]);
        }
        printf("\n");
    }
    printf("your second array is given below\n");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            printf("%d ",arr_second[i][j]);
        }
        printf("\n");
    }
    printf("Multiplication of first and second array is given below\n");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            arr_third[i][j]=arr_first[i][j]*arr_second[i][j];
            printf("%d ",arr_third[i][j]);
        }
        printf("\n");
    }
}