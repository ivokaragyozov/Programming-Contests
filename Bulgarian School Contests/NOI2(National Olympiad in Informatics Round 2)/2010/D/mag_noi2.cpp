/**
Ivo Karagyozov
NOI2 2010 D2 mag
*/
#include<iostream>
using namespace std;
bool isprime(int n)
{
    if(n<2)return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    if(isprime(n))
    {
        cout<<"No"<<endl;
        return 0;
    }
    int n1=n,dels[10005],pos=0,sumdels=0,del=2;
    while(n>1)
    {
        if(isprime(del))
        {
            while(n%del==0 && n!=1)
            {
                dels[pos++]=del;
                sumdels=sumdels+del;
                n=n/del;
            }
        }
        del++;

    }
    for(int i=0;i<n1-sumdels;i++)
    {
        cout<<"1 ";
    }
    for(int i=0;i<pos-1;i++)
    {
        cout<<dels[i]<<" ";
    }
    cout<<dels[pos-1]<<endl;
    return 0;
}
