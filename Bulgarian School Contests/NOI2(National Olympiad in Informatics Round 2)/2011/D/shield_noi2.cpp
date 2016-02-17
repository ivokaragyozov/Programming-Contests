/**
Ivo Karagyozov
NOI2 2011 D3 shield
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[105],b[105];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int mins=10000,s;
    for(int i=0;i<n;i++)
    {
        s=a[i]+b[i];
        if(s<mins)mins=s;
    }
    int h1,h2;
    h1=mins;
    mins=10000;
    for(int i=0,j=n-1;i<n;i++,j--)
    {
        s=a[i]+b[j];
        if(s<mins)mins=s;
    }
    h2=mins;
    cout<<max(h1,h2)<<endl;
    return 0;
}
