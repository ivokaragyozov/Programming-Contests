#include<iostream>
#include<cstdio>
using namespace std;
int br[105];
bool columns[105];
int main()
{
    int n, m;
    cin>>n>>m;
    char tab[105][105];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>tab[i][j];
        }
    }
    int ans=0;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(columns[j]==false)
            {
                cout<<tab[i-1][j]<<" "<<tab[i][j]<<endl;
                if(tab[i-1][j]!=tab[i][j])
                {
                    if(tab[i-1][j]>tab[i][j])
                    {
                        columns[j]=true;
                        ans++;
                    }
                    else break;
                }
            }
        }
    }
    cout<<ans<<endl;
}
