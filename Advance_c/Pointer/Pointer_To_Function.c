#include<stdio.h>
void area(int *h,int *w)
{
    int arr=*h**w;
    printf("Area of Rectangel=%d ",arr);
}
int main()
{
    int x,y;
    printf("Enter height\n");
    scanf("%d",&x);
    printf("Enter Width\n");
    scanf("%d",&y);
    area(&x,&y);

}