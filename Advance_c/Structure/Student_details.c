#include<stdio.h>
#include<string.h>
struct Student
{
    char name[300];
    int roll_no;
    float marks;
};
int main()
{
    struct Student obj;
    strcpy(obj.name,"Belal Ahmad");
    obj.roll_no=201;
    obj.marks=84.9;
    printf("Name=%s\n",obj.name);
    printf("Roll No=%d\n",obj.roll_no);
    printf("Your Marks=%f\n",obj.marks);
}