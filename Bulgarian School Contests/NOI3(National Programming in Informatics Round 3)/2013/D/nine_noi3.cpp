/**
Ivo Karagyozov
NOI3 2013 D6 nine
*/
#include<iostream>
using namespace std;
long long sumd(long long n)
{
    long long sum=0;
    while(n>0)
    {
        sum=sum+n%10;
        n=n/10;
    }
    return sum;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    long long br=0;
    for(long long i=a;i<=b;i++)
    {
        if(sumd(i)==sumd(9*i))br++;
    }
    cout<<br<<endl;
    return 0;
}
