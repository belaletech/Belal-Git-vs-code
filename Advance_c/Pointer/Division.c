#include<stdio.h>
int main()
{
    float a,b,c;
    float *p,*q,*r;
    p=&a;
    q=&b;
    r=&c;
    printf("Enter Two number \n");
    scanf("%f%f",p,q);
    *r=*p/ *q;
    printf("Division=%f ",*r);
}