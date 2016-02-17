/**
Ivo Karagyozov
10/10 correct
*/
#include<iostream>
#include<cstdio>
using namespace std;

const int MAX_VAL=1<<31-1;

struct cow
{
    int pos, speed;
    cow()
    {

    }
    cow(int a, int b)
    {
        pos=a;
        speed=b;
    }
};

int n, minspeed=MAX_VAL, ans=0;
cow cows[1000005];

int main()
{
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int pos, speed;
        cin>>pos>>speed;
        cows[i]=cow(pos, speed);
    }
    for(int i=n-1; i>=0; i--)
    {
        if(cows[i].speed<=minspeed)
        {
            ans++;
            minspeed=cows[i].speed;
        }
    }
    cout<<ans<<endl;
    return 0;
}
