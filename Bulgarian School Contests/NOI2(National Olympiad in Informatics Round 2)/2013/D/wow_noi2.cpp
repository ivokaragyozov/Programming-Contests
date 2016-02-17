/**
Ivo Karagyozov
NOI2 2013 D1 wow
*/
#include<iostream>
using namespace std;
bool p[10005];
int main()
{
    int n;
    cin>>n;
    int a[10005];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int pos=0;
    while(1)
    {
        if(p[pos]==true)break;
        p[pos]=true;
        pos=a[pos];
    }
    int br3=0;
    for(int i=0;i<n;i++)
    {
        if(p[i]==false)br3++;
        p[i]=false;
    }
    p[pos]=true;
    while(1)
    {
        pos=a[pos];
        if(p[pos]==true)break;
        p[pos]=true;
    }
    int br2=0;
    for(int i=0;i<n;i++)
    {
        if(p[i]==true)br2++;
    }
    int br1=n-br2-br3;
    cout<<br1<<" "<<br2<<" "<<br3<<endl;
    return 0;
}
