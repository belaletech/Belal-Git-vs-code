#include<stdio.h>
#include<string.h>
int main()
{
    char s[200];
    int count=0;
    printf("Enter any string\n");
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        count++;
    }
    printf("Length of string is %d",count);
}