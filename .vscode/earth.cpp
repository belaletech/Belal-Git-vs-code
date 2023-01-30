#include<iostream>
using namespace std;
int main()
{
    int n,rem=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        rem=a[i]%10;
    }
    if(rem%10==0)
    {
        cout<<"Yes"<<endl;
    }
    else
    cout<<"No"<<endl;
}