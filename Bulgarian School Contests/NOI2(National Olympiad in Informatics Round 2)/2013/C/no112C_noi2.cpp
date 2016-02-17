/**
Ivo Karagyozov
NOI2 2013 C1 no112C
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int beg,en;
bool p=false;
int used[1005]={0};
vector<int> v[1005];
void dfs(int beg)
{
    used[beg]=1;
    if(beg==en)
    {
        p=true;
        return;
    }
    for(int i=0;i<v[beg].size();i++)
    {
        if(used[v[beg][i]]==0)dfs(v[beg][i]);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int b,e;
        cin>>b>>e;
        v[b].push_back(e);
        v[e].push_back(b);
    }
    for(int i=0;i<m;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    int q;
    cin>>q;
    bool k[100005];
    int j=0;
    for(int i=0;i<q;i++)
    {
        cin>>beg>>en;
        p=false;
        dfs(beg);
        if(p==true)
        {
            k[j]=1;
            j++;
        }
        else
        {
            k[j]=0;
            j++;
        }
        for(int a=0;a<=n;a++)
        {
            used[a]=0;
        }
    }
    for(int i=0;i<j;i++)
    {
        cout<<k[i];
    }
    cout<<endl;
    return 0;
}
