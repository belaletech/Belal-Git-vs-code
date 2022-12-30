#include<stdio.h>
void main()
{
    int n;
    printf("Enter an Integer\n");
    scanf("%d",&n);
    f(n)
    {
    if(n==0)
    {
        return 1;
    }
    else
    return f(n-1)*n;
    }
}