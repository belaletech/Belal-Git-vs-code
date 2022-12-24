#include<stdio.h>
void divide()
{
    int a,b,div,rem;
    printf("Enter Divident\n");
    scanf("%d",&a);
    printf("Enter Divisor\n");
    scanf("%d",&b);
    div=a/b;
    printf("Your Quotient is=%d\n",div);
    rem=a%b;
    printf("Your Reminder=%d\n",rem);
}
int main()
{
    divide();
}