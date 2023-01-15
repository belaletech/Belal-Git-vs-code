#include<stdio.h>
#include<string.h>
void main()
{
    char u[200]="arisetechwithbelal@gmail.com",p[200]="Belal@123";
    char u1[200],p1[200];
    printf("Enter username\n");
    gets(u1);
    printf("Enter password\n");
    gets(p1);
    if(strcmp(u,u1)==0 && strcmp(p,p1)==0)
    printf("Login Successfully");
    else
    printf("Wrong username or Password");
}