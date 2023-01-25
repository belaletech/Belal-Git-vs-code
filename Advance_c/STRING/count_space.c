#include<stdio.h>
//#include<string.h>
int main()
{
    char s[200];
    int space=0;
    printf("Enter any string\n");
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]==' ')
        space++;
    }
    printf("Total space in this Sentance=%d",space);
}
