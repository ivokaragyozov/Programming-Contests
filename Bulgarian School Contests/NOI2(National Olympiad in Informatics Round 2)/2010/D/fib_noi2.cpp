/**
Ivo Karagyozov
NOI2 2010 D1 fib
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s="11";
    long long a=1,b=1,c=0;
    while(s.size()<n)
    {
        c=a+b;
        a=b;
        b=c;

        long long d=c;
        string t;
        while(d>0)
        {
            t=(char)(d%10+'0')+t;
            d=d/10;
        }
        s=s+t;
    }
    cout<<s[n-1]<<endl;
    return 0;
}
