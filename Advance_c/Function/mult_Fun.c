#include<stdio.h>
void mult()
{
    int a,b,mult;
    printf("Enter Two number\n");
    scanf("%d%d",&a,&b);
    mult=a*b;
    printf("Multiply=%d\n",mult);
}
int main()
{
    mult();
    mult();
}
