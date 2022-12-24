#include<stdio.h>
int main()
{
    //A normal integer variable
    int var=10;

    //A pointer variable that holds address of var.
    int*ptr=&var;

    //This line prints value at address stored in ptr.
    //value stored is value of variable "var"
    printf("Value of Var=%d\n",*ptr);

    //The output of this line may be diffrent in diffrent runs even on same machine
    printf("Address of Var=%p\n",ptr);

    //wee can also use ptr as lvalue(left hand side of assingment)
    *ptr=20;

    //this prints 20
    printf("After doing *ptr=20,*ptr is %d\n",*ptr);
    return 0;
}