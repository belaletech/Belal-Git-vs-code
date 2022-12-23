#include<stdio.h>
int main()
{
    int 
    ar[10]={10,20,30,40,50,60,70,80,90,100};
    for(int i=0;i<=9;i++)
    {
        printf("%d\n",*(ar+i));
    }
}