#include<stdio.h>
void swap(int*,int*);
int main()
{
    int a,b;
    printf("Enter Two numbers\n");
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("a=%d and b=%d",a,b);
    return 0;
}
void swap( int *p,int *q)
{
    int t;
    t=*p;
    *p=*q;
    *q=t;

}
