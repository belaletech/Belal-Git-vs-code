#include<stdio.h>
#include<stdio.h>
int main()
{
    char s[200];
    int alpha=0;
    printf("Enter any String\n");
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))
        alpha++;
    }
    printf("Total Alphabet=%d",alpha);
}