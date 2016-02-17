/**
Ivo Karagyozov
Proleten 2007 D1 tab
*/
#include<iostream>
#include<vector>
using namespace std;
int n,m,a[105][105];
vector<int> x,y;
void dfs(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=n || a[i][j]==0)return;
    x.push_back(i);
    y.push_back(j);
    a[i][j]=0;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            a[i][j]=c-'0';
        }
    }
    dfs(0,0);
    int br=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            bool p=false;
            for(int k=0;k<x.size();k++)
            {
                if(i+x[k]>n || j+y[k]>m || a[i+x[k]][j+y[k]]==0)
                {
                    p=true;
                    break;
                }
            }
            if(p==false)
            {
                br++;
            }
        }
    }
    br++;
    cout<<br<<endl;
    return 0;
}
