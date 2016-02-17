/**
Ivo Karagyozov
Esenen 2012 B1 balance
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 15;

bool used[maxN];
int n, a[maxN];

int solve(int sumR, int sumL, int currCnt)
{
    if(sumL > sumR) return 0;
    if(currCnt == n) return 1;

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            used[i] = true;
            ans += solve(sumR + a[i], sumL, currCnt + 1);
            ans += solve(sumR, sumL + a[i], currCnt + 1);
            used[i] = false;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    cout<<solve(0, 0, 0)<<endl;
    return 0;
}
