#include<stdio.h>
#include<string.h>
int main()
{
    char s[200];
    int digit=0;
    printf("Enter any String\n");
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>=48&&s[i]<=57)
        digit++;
    }
    printf("Total Digits=%d",digit);
}