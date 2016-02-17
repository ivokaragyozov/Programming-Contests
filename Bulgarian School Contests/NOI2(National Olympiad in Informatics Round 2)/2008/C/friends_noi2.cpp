/**
Ivo Karagyozov
NOI2 2008 C1 friends
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
queue<int> qu;
vector<int> v[2005];
bool used[2005];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    qu.push(1);
    used[1]=true;
    int siz=1, maxsiz=1;
    while(!qu.empty())
    {
        siz=qu.size();
        if(siz>maxsiz)maxsiz=siz;
        for(int i=0; i<siz; i++)
        {
            int a=qu.front();
            qu.pop();
            for(int j=0; j<v[a].size(); j++)
            {
                if(used[v[a][j]]==false)
                {
                    used[v[a][j]]=true;
                    qu.push(v[a][j]);
                }
            }
        }
    }
    printf("%d\n", maxsiz);
    return 0;
}
