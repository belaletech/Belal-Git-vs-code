#include<stdio.h>
int main()
{
    char s[500];
    int vowel=0,consonat=0;
    printf("Enter any String\n");
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        vowel++;
        else
        consonat++;
    }
    printf("Total Number of Vowel =%d and Consonant=%d",vowel,consonat);
}