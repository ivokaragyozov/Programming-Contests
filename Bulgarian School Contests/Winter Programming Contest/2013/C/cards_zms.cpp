/**
Ivo Karagyozov
Zimni 2013 C3 cards
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1005;

int n, dp[maxN][maxN][3], parent[maxN][maxN][3];
string s, t, ans;

bool solve(int ind1, int ind2, int diff)
{
    cout<<ind1<<" "<<ind2<<" "<<diff<<endl;
    if(ind1 == 0 && ind2 == 0 && diff == 1) return true;
    if(ind1 < 0 || ind2 < 0 || diff < 0 || diff > 2) return false;
    if(dp[ind1][ind2][diff] != -1) return dp[ind1][ind2][diff];

    if(solve(ind1 - 1, ind2, diff + (s[ind1] == '0' ? -1 : 1)))
    {
        parent[ind1][ind2][diff] = 1;
        cout<<"left "<<ind1<<" "<<ind2<<" "<<diff<<endl;
        dp[ind1][ind2][diff] = true;
        return true;
    }
    if(solve(ind1, ind2 - 1, diff + (t[ind2] == '0' ? -1 : 1)))
    {
        dp[ind1][ind2][diff] = true;
        parent[ind1][ind2][diff] = true;
        cout<<"right "<<ind1<<" "<<ind2<<" "<<diff<<endl;
        return true;
    }

    return false;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin>>n>>s>>t;
    s = " " + s;
    t = " " + t;
    solve(n, n, 1);

    int i = n, j = n, diff = 1;

    while(i != 0 || j != 0)
    {
        cout<<i<<" "<<j<<" "<<" "<<ans<<" "<<diff<<endl;
        if(parent[i][j][diff] == 1)
        {
            ans += '1';
            diff += (s[i] == '0' ? -1 : 1);
            i--;
        }
        else
        {
            break;
            ans += '2';
            diff += (t[j] == '0' ? -1 : 1);
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    return 0;
}
