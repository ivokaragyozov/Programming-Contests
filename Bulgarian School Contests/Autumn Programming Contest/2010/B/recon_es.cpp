#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1029;

struct path
{
    int from, to, w;

    path(){}
    path(int from, int to, int w)
    {
        this->from = from;
        this->to = to;
        this->w = w;
    }
};

int n, a, ind, parent[maxN], height[maxN], x, y;
path paths[maxN * maxN];
vector<int> graph[maxN];

bool cmp(path x, path y)
{
    return x.w < y.w;
}
int findParent(int u)
{
    if(parent[u] != u) parent[u] = findParent(parent[u]);
    else return parent[u];
}
void unionSet(int parentX, int parentY)
{
    if(height[parentX] < height[parentY]) parent[parentX] = parentY;
    else if(height[parentX] > height[parentY]) parent[parentY] = parentX;
    else
    {
        parent[parentX] = parentY;
        height[parentY]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            cin>>a;

            paths[ind++] = path(i, i + j + 1, a);
        }

        parent[i] = i;
    }
    parent[n - 1] = n - 1;

    sort(paths, paths + ind, cmp);

    for(int i = 0; i < ind; i++)
    {
        x = paths[i].from;
        y = paths[i].to;

        int parentX = findParent(x), parentY = findParent(y);
        if(parentX != parentY)
        {
            unionSet(parentX, parentY);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout<<graph[i].size();

        sort(graph[i].begin(), graph[i].end());
        for(int j = 0; j < graph[i].size(); j++)
        {
            cout<<" "<<graph[i][j] + 1;
        }
        cout<<endl;
    }
    return 0;
}
