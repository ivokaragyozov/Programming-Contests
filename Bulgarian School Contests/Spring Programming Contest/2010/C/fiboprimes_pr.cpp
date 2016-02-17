/**
Ivo Karagyozov
Proleten 2010 C3 fiboprimes
*/
#include<iostream>
#include<map>
#include<cmath>
#define endl '\n'
using namespace std;

long long n, fibs[70], indf=1;
map<long long, short> dp;
map<long long, bool> used;

void init()
{
    fibs[0]=1;
    fibs[1]=1;
    for(int i=2; fibs[i-1]+fibs[i-2]<=n; i++)
    {
        indf=i;
        fibs[i]=fibs[i-1]+fibs[i-2];
    }
}
bool isPrime(long long a)
{
    if(a<2)return false;
    else if(a==2)return true;
    else if(a%2==0)return false;
    for(int i=3; i<=sqrt(a); i+=2)
    {
        if(a%i==0)return false;
    }
    return true;
}
int brPrimes(long long a)
{
    if(used[a]==1)
    {
        return dp[a];
    }
    int maxprimes=0;
    int p=isPrime(a);
    for(int i=2; fibs[i]<=a && i<=indf; i++)
    {
        int tmp=brPrimes(a/fibs[i]);
        if(tmp>maxprimes)
        {
            maxprimes=tmp;
        }
    }
    used[a]=1;
    dp[a]=maxprimes+p;
    return dp[a];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    init();
    cout<<brPrimes(n)<<endl;
    return 0;
}
