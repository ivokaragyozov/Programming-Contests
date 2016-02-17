/**
Ivo Karagyozov
NOI3 2013 D4 primecnt
*/
#include<iostream>
using namespace std;
const int N=1000005;
int p[N];
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
    int c=0;
    for(int i=1;i<=1000000;i++)
    {
        if(isprime(i)==true)c++;
        p[i]=c;
    }
    int k;
    cin>>k;
    int a,b;
    for(int i=0;i<k;i++)
    {
        cin>>a>>b;
        cout<<p[b]-p[a-1]<<endl;
    }
    return 0;
}
