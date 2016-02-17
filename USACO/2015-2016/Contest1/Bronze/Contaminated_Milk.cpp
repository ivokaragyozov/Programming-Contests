#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 55, maxM = 55;

bool vis[maxN][maxM], pos[maxM], p;
int n, m, d, s, a, b, c, milks[maxM], currCnt, maxCnt;
vector<int> drinks[maxN][maxM];

int main()
{
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(pos, 1, sizeof(pos));

    cin>>n>>m>>d>>s;
    for(int i = 0; i < d; i++)
    {
        cin>>a>>b>>c;

        vis[a][b] = true;
        drinks[a][b].push_back(c);
    }

    for(int i = 0; i < s; i++)
    {
        cin>>a>>b;

        for(int j = 1; j <= m; j++)
        {
            p = false;
            for(int k = 0; k < drinks[a][j].size(); k++)
            {
                if(drinks[a][j][k] < b)
                {
                    p = true;
                    break;
                }
            }

            if(!p) pos[j] = false;
        }
    }

    for(int i = 1; i <= m; i++)
    {
        if(pos[i])
        {
            currCnt = 0;
            for(int j = 1; j <= n; j++)
            {
                if(vis[j][i]) currCnt++;
            }

            if(currCnt > maxCnt) maxCnt = currCnt;
        }
    }

    cout<<maxCnt<<endl;
    return 0;
}
