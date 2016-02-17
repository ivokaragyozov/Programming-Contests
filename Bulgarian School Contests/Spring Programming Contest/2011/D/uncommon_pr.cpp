/**
Ivo Karagyozov
Prolenten 2010 D2 uncommon
*/
#include<iostream>
using namespace std;
long long nod(long long a,long long b)
{
    while(b>0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long turn(long long a)
{
    long long b=0;
    while(a>0)
    {
        b=b*10+a%10;
        a=a/10;
    }
    return b;
}
int main()
{
    long long a,b,n,m;
    cin>>a>>b>>n>>m;
    long long nod1=nod(n,m);
    n=n/nod1;
    m=m/nod1;
    if(a%n!=0)a=(a/n+1)*n;
    long long br=0;
    for(int i=a;i<=b;i+=n)
    {
        int q=i/n*m;
        if(i==turn(q))br++;
    }
    cout<<br<<endl;
    return 0;
}
