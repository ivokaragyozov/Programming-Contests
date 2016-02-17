#include <iostream>
#define endl '\n'
using namespace std;

long long n, ans=0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
}

int main()
{
    input();
    if(n<10)
    {
        cout<<n<<endl;
        return 0;
    }
    ans=9;
    if(n<100)
    {
        ans+=(n-10+1)*2;
        cout<<ans<<endl;
        return 0;
    }
    ans+=180;
    if(n<1000)
    {
        ans+=(n-100+1)*3;
        cout<<ans<<endl;
        return 0;
    }
    ans+=2700;
    if(n<10000)
    {
        ans+=(n-1000+1)*4;
        cout<<ans<<endl;
        return 0;
    }
    ans+=36000;
    if(n<100000)
    {
        ans+=(n-10000+1)*5;
        cout<<ans<<endl;
        return 0;
    }
    ans+=450000;
    if(n<1000000)
    {
        ans+=(n-100000+1)*6;
        cout<<ans<<endl;
        return 0;
    }
    ans+=5400000;
    if(n<10000000)
    {
        ans+=(n-1000000+1)*7;
        cout<<ans<<endl;
        return 0;
    }
    ans+=63000000;
    if(n<100000000)
    {
        ans+=(n-10000000+1)*8;
        cout<<ans<<endl;
        return 0;
    }
    ans+=720000000;
    if(n<1000000000LL)
    {
        ans+=(n-100000000LL+1)*9;
        cout<<ans<<endl;
        return 0;
    }
    ans+=8100000000LL;
    if(n<10000000000LL)
    {
        ans+=(n-1000000000LL+1)*10;
        cout<<ans<<endl;
        return 0;
    }
}

