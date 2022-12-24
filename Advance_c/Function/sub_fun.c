#include<stdio.h>
void sub()
{
    int a,b,sub;
    printf("Enter Two number\n");
    scanf("%d%d",&a,&b);
    sub=a-b;
    printf("Sub=%d",sub);
}
int main()
{
    sub();
}