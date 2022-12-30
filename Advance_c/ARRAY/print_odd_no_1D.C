#include<stdio.h>
int main()
{
	int a[100],n;
	printf("Enter how many number you want to store \n");
	scanf("%d",&n);
	printf("Enter %d number one by one\n",n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf("Array element is given below\n");
	for(int j=0;j<n;j++)
	printf("%d ",a[j]);
	
	printf("\nOdd number in array is given below\n");
	for(int k=0;k<n;k++)
	{
		if(a[k]%2!=0)
		printf("%d ",a[k]);
	}
}