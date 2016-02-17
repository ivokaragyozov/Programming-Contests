/**
Ivo Karagyozov
Proleten 2014 E2 suma
*/
#include<iostream>
using namespace std;
long long gaos(long long n,long long m)
{
    long long sum=0;
    long long brnums=m-n+1;
    sum=(brnums/2)*(n+m);
    if(brnums%2!=0)
    {
        sum+=(n+m)/2;
    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    long long n,m,k;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m>>k;
        if(k%2==0)cout<<"YES"<<endl;
        else
        {
            if(gaos(n,m)%2==0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
