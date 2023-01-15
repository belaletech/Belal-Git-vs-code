#include<stdio.h>
void main()
{
    int array[3][3]={{3,2,5},{8,9,6},{8,7,2}};
    int i,j;
    printf("Array is given below\n");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    printf("Transpose of Array is given below\n");
    for(i=0;i<=2;i++)
    {
        for (j=0;j<=2;j++)
        {
          printf("%d ",array[j][i]);  
        }
        printf("\n");
        
    }
}