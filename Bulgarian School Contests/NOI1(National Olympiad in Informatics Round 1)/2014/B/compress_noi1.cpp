/**
Ivo Karagyozov
NOI1 2014 B1 compress
*/
#include<iostream>
#define endl '\n'
using namespace std;

int n, a;
long long dp[105];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>a;
}
void output()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<dp[n]<<endl;
}

int main()
{
    input();
    dp[0]=1;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=a; j++)
        {
            dp[i+j]+=dp[i];
        }
    }
    output();
    return 0;
}
