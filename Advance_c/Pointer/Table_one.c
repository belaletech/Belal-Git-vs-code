#include<stdio.h>
int main()
{
    int a=1;
    int *p;
    p=&a;
    while (*p<=10)
    {
       printf("%d\n",*p);
       (*p)++;
    }
    
}