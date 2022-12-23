#include<stdio.h>
struct Student
{
    int rollno;
};

int main()
{
    struct Student obj_roll;
  obj_roll.rollno=205;
  struct Student *r,*m;
  r=&obj_roll;
  printf("Roll number=%d\n",*r);
}