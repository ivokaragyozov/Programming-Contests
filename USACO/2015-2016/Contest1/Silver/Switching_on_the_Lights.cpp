#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

struct ceilStruct
{
    int i, j;

    ceilStruct(){}
    ceilStruct(int i, int j)
    {
        this->i = i;
        this->j = j;
    }
};

bool lighted[maxN][maxN], vis[maxN][maxN];
int n, m, a, b, x, y, ans;
vector<ceilStruct> switches[maxN][maxN];
queue<ceilStruct> q;

bool nearest(int i, int j)
{
    if(i > 1 && vis[i - 1][j]) return true;
    if(j < n && vis[i][j + 1]) return true;
    if(i < n && vis[i + 1][j]) return true;
    if(j > 1 && vis[i][j - 1]) return true;

    return false;
}
void bfs()
{
    int currX, currY;
    q.push(ceilStruct(1, 1));

    while(!q.empty())
    {
        currX = q.front().i;
        currY = q.front().j;
        q.pop();

        if(vis[currX][currY]) continue;
        vis[currX][currY] = true;
        //cout<<currX<<" "<<currY<<endl;

        for(int i = 0; i < switches[currX][currY].size(); i++)
        {
            lighted[switches[currX][currY][i].i][switches[currX][currY][i].j] = true;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(!vis[i][j] && lighted[i][j] && nearest(i, j)) q.push(ceilStruct(i, j));
            }
        }
    }
}

int main()
{
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lighted[1][1] = true;

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>x>>y;

        switches[a][b].push_back(ceilStruct(x, y));
    }

    bfs();

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(lighted[i][j]) ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}
