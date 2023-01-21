#include<stdio.h>
#include<string.h>
int main()
{
    char s[300];
    int special=0;
    printf("Enter any String\n");
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))
        {

        }
        else if(s[i]>=48&&s[i]<=57)
        {

        }
        else
        special++;
    }
    printf("Total Symbol=%d",special);
}