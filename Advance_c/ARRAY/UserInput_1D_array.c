#include<stdio.h>
int main(){
    int ar[4];
    for(int i=0; i<=3;i++)
        {
        printf("Enter %d element\n",i+1);
        scanf("%d",&ar[i]);
        
         }
    printf("Element is given Below\n");
    for(int j=0;j<=3;j++)
    {
        printf("%d  ",ar[j]);
    }
}