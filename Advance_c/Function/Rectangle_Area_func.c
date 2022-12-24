#include<stdio.h>
void  Area(int Height,int Width)
{
    int ar=Height*Width;
    printf("Area of rectangle=%d",ar);
}
int main()
{
    int h,w;
    printf("Enter Height of Rectangle\n");
    scanf("%d",&h);
    printf("Enter Width of Rectangle\n");
    scanf("%d",&w);
    Area(h,w);
}