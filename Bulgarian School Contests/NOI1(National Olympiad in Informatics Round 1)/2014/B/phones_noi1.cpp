#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 5;

bool k;
int n, m, p, cnt[100000], b[maxN];
double a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        p = a * 100;

        cnt[p]++;
    }

    for(int i = 0; i < m; i++)
    {
        cin>>a;
        p = a * 100;

        cnt[p]--;
    }

    for(int i = 40000; i >= 0; i--)
    {
        while(cnt[i] > 0)
        {
            if(!k)
            {
                cout<<i / 100<<"."<<i % 100;
                k = true;
            }
            else cout<<" "<<i / 100<<"."<<i % 100;

            cnt[i]--;
        }
    }

    cout<<endl;
    return 0;
}
