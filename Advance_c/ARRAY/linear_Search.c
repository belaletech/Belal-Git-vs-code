#include<stdio.h>
int main()
{
    int roll[10]={24,22,21,33,46,53,76,88,99,66};
    int r,m=0;
    printf("Roll number is given below\n");
    for(int i=0;i<9;i++)
    printf("%d  ",roll[i]);

    printf("\nEnter your roll no to search\n");
    scanf("%d",&r);
    for(int j=1;j<9;j++)
    {
        if(r==roll[j])
    {
        printf("Roll no is found at position =%d",j+1);
        m=1;
    }
    }
    if(m==0)
    printf("Not found");
}
