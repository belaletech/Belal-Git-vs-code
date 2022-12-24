#include<stdio.h>
void Area(float radius)
{
    float ar=3.14*radius*radius;
    printf("Area of Circle=%f",ar);
}
int main()
{
    float r;
    printf("Enter the Radius of Circle\n");
    scanf("%f",&r);
    Area(r);
}