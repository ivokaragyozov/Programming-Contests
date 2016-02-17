/**
Ivo Karagyozov
NOI3 2011 D3 lottery
*/

#include<iostream>
using namespace std;
int br[100000];
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[100000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int p,q;
    cin>>p>>q;
    int br[100000];
    for(int i=0;i<n;i++)
    {
        int b=p;
        if(b%a[i]!=0)b=(b/a[i]+1)*a[i];
        for(int j=b;j<=q;j=j+a[i])
        {
            br[j-p]++;
        }
    }
    int br1=0;
    for(int i=0;i<q-p+1;i++)
    {
        if(br[i]==k)br1++;
    }
    cout<<br1<<endl;
    return 0;
}
