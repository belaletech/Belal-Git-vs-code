#include<stdio.h>
int main()
{
	int n,rem=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",a[i]);
	}
	for(int i=0;i<n;i++)
	{
		rem=a[i]%10;
	}
	if(rem%10==0)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	

}