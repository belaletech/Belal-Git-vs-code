#include<stdio.h>
void Belal()
{
    int a=10;
    int *p; //Declare pointer variable
    p=&a;//note that data type of a and p must be same

    //assign the address of a variable to a pointer
    printf("Value at p=%p \n",p);
    printf("value at a=%d\n",a);
    printf("value at *p=%d\n",*p);
}
int main()
{
    Belal();
    return 0;
}