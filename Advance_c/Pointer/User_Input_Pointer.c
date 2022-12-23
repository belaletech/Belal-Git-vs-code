#include<stdio.h>
int main()
{
    int a,b,c;
    int *p,*q,*r;
    p=&a;
    q=&b;
    r=&c;
    printf("Enter your First Number\n");
    scanf("%d",q);
    printf("Enter your second Number\n");
    scanf("%d",r);
    *p=*q+*r;
    printf("Add=%d ",*p);
}