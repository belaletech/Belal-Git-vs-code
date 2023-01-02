#include<stdio.h>
int main()
{
    int a[3][3]={{3,2,1},{5,9,8},{2,8,4}};
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}