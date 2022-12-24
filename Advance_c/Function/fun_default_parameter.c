#include<stdio.h>
int add(int y=10,int z=30)
{
    int sum;
    sum=y+z;
    printf("Add=%d\n",sum);
}
int main()
{
    printf("Without parameter\n");
    add();
    printf("With parameter\n");
    add(80,90);
}