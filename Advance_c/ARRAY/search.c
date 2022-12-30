#include<stdio.h>
int main()
{
    int roll[10]={10,11,12,13,14,15,16,17,18,19};
    int r,m=0;
    printf("Roll number is given below\n ");
    for(int i=0;i<=9;i++)
    printf("%d  ",roll[i]);

    printf("\n Enter your roll no to search \n");
    scanf("%d",&r);
    for(int j=1;j<=9;j++)
    {
        if(r==roll[j])
        {
            printf("Roll no is foud at position =%d",j+1);
            m=1;
        }
    }
    if(m==0)
    printf("Not found");
    return 0;
}