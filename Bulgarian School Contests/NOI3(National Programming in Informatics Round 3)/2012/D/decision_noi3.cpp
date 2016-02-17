/**
Ivo Karagyozov
NOI3 2012 D1 decision
*/
#include<iostream>
using namespace std;
int main()
{
    int x,y,n,m,k;
    cin>>x>>y>>n>>m>>k;
    long long mins,mina,mint;
    for(int i=0;k-i*n>=0;i++)
    {
        int bra=i,brt=0;
        if((k-i*n)%m==0)brt=(k-i*n)/m;
        else brt=(k-i*n)/m+1;
        if(i==0 ||  bra*x+brt*y<mins)
        {
            mins=bra*x+brt*y;
            mina=bra;
            mint=brt;
        }
    }
    for(int i=0;k-i*m>=0;i++)
    {
        int bra,brt=i;
        if((k-i*m)%n==0)bra=(k-i*m)/n;
        else bra=(k-i*m)/n+1;
        if(bra*x+brt*y<mins)
        {
            mins=bra*x+brt*y;
            mina=bra;
            mint=brt;
        }
    }
    cout<<mina<<" "<<mint<<endl;
    return 0;
}
