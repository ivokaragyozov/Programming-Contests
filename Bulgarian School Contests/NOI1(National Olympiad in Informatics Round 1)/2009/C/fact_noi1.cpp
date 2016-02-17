/**
Ivo Karagyozov
NOI1 2009 C2 fact
*/
#include<iostream>
#include<cstdio>
using namespace std;
bool isPrime(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)return false;
    }
    return true;
}
int brPrimeDels(int n)
{
    int br=0;
    for(int i=2; ; i++)
    {
        if(isPrime(i)==true)
        {
            while(n%i==0)
            {
                n=n/i;
                br++;
            }
        }
        if(n==1)break;
    }
    return br;
}
int main()
{
    int n;
    scanf("%d", &n);
    long long sum=0;
    for(int i=2; i<=n; i++)
    {
        if(isPrime(i)==true)
        {
            sum++;
        }
        else
        {
            sum+=brPrimeDels(i);
        }
    }
    printf("%lld\n", sum);
    return 0;
}
