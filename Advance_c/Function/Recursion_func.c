#include<stdio.h>
int table(int no)
{
    if(no!=11)
    {
        printf("%d\n",no);
        no++;
        table(no);
    }
}
int main()
{
    table(1);
}