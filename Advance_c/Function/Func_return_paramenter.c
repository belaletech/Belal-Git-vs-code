#include<stdio.h>
int add(int x,int y)
{
    int sum;
    sum=x+y;
    return sum;
}
int main()
{
    printf("Add=%d",add(90,80));
}