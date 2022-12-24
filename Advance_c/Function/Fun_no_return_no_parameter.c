#include<stdio.h>
void add()
{
    int x,y,sum;
    printf("Enter two number\n");
    scanf("%d%d",&x,&y);
     sum=x+y;
    printf("Sum of Two number=%d",sum);
}
int main()
{
    add();
}