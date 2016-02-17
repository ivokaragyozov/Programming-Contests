/**
Ivo Karagyozov
Esenen 2012 C3 tvagme
*/
#include <iostream>

using namespace std;

struct ceil
{
    int i;
    int j;
};

char table[1005][1005];
int maxSum[1005][1005], isPos[1005][1005];
ceil par[1005][1005];

int main()
{
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>table[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int maxs=0;
            if(table[i][j]>='0' && table[i][j]<='9')maxs=table[i][j]-'0';

            if(i!=0)
            {
                if(j!=0 && (table[i-1][j-1]=='R' || table[i-1][j-1]=='X') && isPos[i-1][j-1]==1)
                {
                    if(maxSum[i-1][j-1]>=maxSum[i][j])
                    {
                        maxSum[i][j]=maxSum[i-1][j-1];
                        par[i][j].i=i-1;
                        par[i][j].j=j-1;
                    }
                    isPos[i][j]=1;
                }
                if(j!=m-1 && (table[i-1][j+1]=='L' || table[i-1][j+1]=='X') && isPos[i-1][j+1]==1)
                {
                    if(maxSum[i-1][j+1]>=maxSum[i][j])
                    {
                        maxSum[i][j]=maxSum[i-1][j+1];
                        par[i][j].i=i-1;
                        par[i][j].j=j+1;
                    }
                    isPos[i][j]=1;
                }
                if((table[i-1][j]=='.' || table[i-1][j]=='X' || (table[i-1][j]>='0' && table[i-1][j]<='9')) && isPos[i-1][j]==1)
                {
                    if(maxSum[i-1][j]>=maxSum[i][j])
                    {
                        maxSum[i][j]=maxSum[i-1][j];
                        par[i][j].i=i-1;
                        par[i][j].j=j;
                    }
                    isPos[i][j]=1;
                }
                if(isPos[i][j]==1)maxSum[i][j]+=maxs;
            }
            else
            {
                isPos[i][j]=1;
                maxSum[i][j]=maxs;
            }
        }
    }

    int maxCeil=0, maxs=0;
    for(int i=0; i<m; i++)
    {
        if(maxSum[n-1][i]>maxs && isPos[n-1][i]==1)
        {
            maxs=maxSum[n-1][i];
            maxCeil=i;
        }
    }

    string road;
    for(int i=n-1; i>0; i--)
    {
        if(par[i][maxCeil].i==i-1 && par[i][maxCeil].j==maxCeil-1)
        {
            road='R'+road;
            maxCeil=maxCeil-1;
        }
        else if(par[i][maxCeil].i==i-1 && par[i][maxCeil].j==maxCeil)
        {
            road='D'+road;
        }
        else if(par[i][maxCeil].i=i-1 && par[i][maxCeil].j==maxCeil+1)
        {
            road='L'+road;
            maxCeil=maxCeil+1;
        }
    }

    cout<<maxs<<endl;
    cout<<maxCeil+1<<endl;
    cout<<road<<endl;
    return 0;
}
