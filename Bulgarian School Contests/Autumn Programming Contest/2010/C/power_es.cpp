/**
Ivo Karagyozov
Esenen 2010 C2 power
*/
#include<iostream>
using namespace std;
long long m;
long long quickStep(long long num, int s)
{
    if(s==1)return num%m;
    else if(s%2==0)return (quickStep(num, s/2)*quickStep(num, s/2))%m;
    else return (quickStep(num, s-1)*num)%m;
}
int main()
{
    long long n;
    cin>>n>>m;
    long long sum=0;
    for(int i=2; i<=n+1; i++)
    {
        long long num;
        cin>>num;
        long long step = quickStep(num, i);
        sum=sum+step;
        if(sum>=m)sum=sum%m;
    }
    cout<<sum<<endl;
    return 0;
}
