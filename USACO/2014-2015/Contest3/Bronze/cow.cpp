#include <iostream>
#include <cstdio>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

long long n, cntC[maxN], cntW[maxN], ans;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("cow.in", "r", stdin);
    freopen("cow.out", "w", stdout);

    cin>>n>>s;

    for(int i = 0, j = n - 1; i < n; i++, j--)
    {
        if(s[i] == 'C')
        {
            if(i != 0) cntC[i] = cntC[i - 1] + 1;
            else cntC[0] = 1;
        }
        else
        {
            if(i != 0) cntC[i] = cntC[i - 1];
            else cntC[0] = 0;
        }

        if(s[j] == 'W')
        {
            if(j != n - 1) cntW[j] = cntW[j + 1] + 1;
            else cntW[n - 1] = 1;
        }
        else
        {
            if(j != n - 1) cntW[j] = cntW[j + 1];
            else cntW[0] = 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'O') ans += cntC[i] * cntW[i];
    }

    cout<<ans<<endl;
    return 0;
}

