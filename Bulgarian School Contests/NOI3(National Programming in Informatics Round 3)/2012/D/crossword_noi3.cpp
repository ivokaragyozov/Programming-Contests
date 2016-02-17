/**
Ivo Karagyozov
NOI3 2012 D3 crossword
*/
#include<iostream>
using namespace std;
int board[25][25];
int mr[25][25];
int mr1[25][25];
int n,m;
int p=1,p1=1;
void hor()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mr[i][j]==0)
            {
                int t=0,j1=j;
                while(j1<m && mr[i][j1]==0)
                {
                    t++;
                    j1++;
                }
                if(t>=2)
                {
                    while(j<j1)
                    {
                        mr[i][j]=p;
                        j++;
                    }
                    p++;
                }
            }
        }
    }
}
void vert()
{
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(mr1[i][j]==0)
            {
                int t=0,i1=i;
                while(i1<n && mr1[i1][j]==0)
                {
                    t++;
                    i1++;
                }
                if(t>=2)
                {
                    while(i<i1)
                    {
                        mr1[i][j]=p1;
                        i++;
                    }
                    p1++;
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
            mr[i][j]=board[i][j];
            mr1[i][j]=board[i][j];
        }
    }
    hor();
    vert();
    cout<<p-1<<" "<<p1-1<<endl;
    int k;
    cin>>k;
    int br1=0,br2=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mr[i][j]==k)br1++;
            if(mr1[i][j]==k)br2++;
        }
    }
    cout<<br1<<" "<<br2<<endl;
    int r,c;
    cin>>r>>c;
    cout<<mr[r-1][c-1]<<" "<<mr1[r-1][c-1]<<endl;
    return 0;
}
