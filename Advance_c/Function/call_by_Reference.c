#include<stdio.h>
void add(int *y,int *z)
{
    int sum;
    sum=*y+*z;
    printf("Add=%d",sum);
}
int main()
{
    int a=20,b=80;
    add(&a,&b);
}
