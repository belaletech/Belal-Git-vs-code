#include<stdio.h>
#include<string.h>
void main()
{
    char ayan[200];
    printf("Enter mobile number\n");
    gets(ayan);
    if(strlen(ayan)==10)
    printf("Number is correct");
    else
    printf("Incorrect number");
}