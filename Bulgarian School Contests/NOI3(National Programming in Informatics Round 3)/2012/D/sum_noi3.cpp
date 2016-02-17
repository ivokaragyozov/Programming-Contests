/**
Ivo Karagyozov
NOI3 2012 D2 sum
*/
#include<iostream>
using namespace std;
long long nod(long long a,long long b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    long long p,q;
    cin>>p>>q;
    unsigned long long sum=0;
    long long nok=(p*q)/nod(p,q);
    a=(a/nok+1)*nok;
    for(long long i=a;i<=b;i+=nok)
    {
        sum=sum+i;
    }
    cout<<sum<<endl;
    return 0;
}
