#include<stdio.h>
#include<string.h>
int main()
{
    char s[200];
    int length=0;
    printf("Enter any String\n");
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    length++;
    printf("Reverse of %s is given below\n",s);
    for(int j=length-1;j>=0;j--)
    printf("%c",s[j]);
}