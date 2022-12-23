#include<stdio.h>
int main()
{
    int a,b,c;
    int *p,*q,*r;
    p=&a;
    q=&b;
    r=&c;
    printf("Enter Two number\n");
    scanf("%d%d",p,q);
    *r=*p**q;
    printf("Multiply=%d ",*r);
}