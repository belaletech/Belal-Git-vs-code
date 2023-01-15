#include<stdio.h>
#include<string.h>
void main()
{
    char s[200],rev[200];
    printf("Enter any string\n");
    gets(s);
    strcpy(rev,s);
    strrev(rev);
    if(strcmp(s,rev)==0)
    printf("%s is Palindrom string",s);
    else
    printf("%s is not palindrom string",s);
}