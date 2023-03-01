#include<stdio.h>
int main()
{
    int a[50][50],sum=0,row,col;
    int b[50][50];
    int i,j;
    printf("Enter row\n");
    scanf("%d",&row);
    printf("Enter column\n");
    scanf("%d",&col);
    printf("Enter %d value one by one \n",row*col);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Element of array is given below\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",a[i][j]);
            
        }
        printf("\n");
    }
    printf("Transpose of Matrix is given below\n");
        
            printf("%d ", a[j][i]);
        
        printf("\n");
    }
    printf("Sum of two matrix is given below\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            
            sum=sum+a[i][j];
        }
        printf("\n");
    }
    printf("Total sum=%d\n",sum);
    printf("Multiplication of first and second array is given below\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            a[i][j]=a[i][j]*a[i][j];
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}