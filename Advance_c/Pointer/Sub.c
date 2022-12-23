#include<stdio.h>
int main()
{
    int a,b,c;
    int *p,*q,*r;
    p=&a;
    q=&b;
    r=&c;
    printf("Enter your two number\n");
    scanf("%d%d",p,q);
    *r=*p-*q;
    printf("Sub=%d ",*r);

}