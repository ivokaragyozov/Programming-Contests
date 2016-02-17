#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1005, maxM = 1005;

bool vis[maxN][maxM];
char table[maxN][maxM];
int n, m, components[maxN][maxM], cntInComponent[maxM * maxN], k, x, y, currCnt, ind = 1;

void dfs(int i, int j)
{
    vis[i][j] = true;
    components[i][j] = ind;

    if(i - 1 >= 0 && table[i - 1][j] == '*') currCnt++;
    else if(i - 1 >= 0 && !vis[i - 1][j]) dfs(i - 1, j);

    if(j + 1 < m && table[i][j + 1] == '*') currCnt++;
    else if(j + 1 < m && !vis[i][j + 1]) dfs(i, j + 1);

    if(i + 1 < n && table[i + 1][j] == '*') currCnt++;
    else if(i + 1 < n && !vis[i + 1][j]) dfs(i + 1, j);

    if(j - 1 >= 0 && table[i][j - 1] == '*') currCnt++;
    else if(j - 1 >= 0 && !vis[i][j - 1]) dfs(i, j - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>table[i][j];
        }
    }

    for(int i = 0; i < k; i++)
    {
        cin>>x>>y;
        x--;
        y--;

        currCnt = 0;
        if(components[x][y] == 0)
        {
            dfs(x, y);
            cntInComponent[ind++] = currCnt;
            cout<<currCnt<<endl;
        }
        else cout<<cntInComponent[components[x][y]]<<endl;
    }

    return 0;
}
