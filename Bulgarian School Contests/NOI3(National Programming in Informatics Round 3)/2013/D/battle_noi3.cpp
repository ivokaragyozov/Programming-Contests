/**
Ivo Karagyozov
NOI3 2013 D5 battle
*/
#include<iostream>
using namespace std;
const int N=1005;
int board[N][N];
int main()
{
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]==2)
            {
                cin>>board[i][j];
                if(board[i][j]==0)board[i][j]=2;
            }
            else cin>>board[i][j];
            if(board[i][j]==1)
            {
                if(i+1<n)
                {
                    if(board[i+1][j]==0)board[i+1][j]=2;
                    if(j+1<m)
                    {
                        if(board[i+1][j+1]==0)board[i+1][j+1]=2;
                    }
                }
                if(i-1>=0)
                {
                    if(board[i-1][j]==0)board[i-1][j]=2;
                    if(j-1>=0)
                    {
                        if(board[i-1][j-1]==0)board[i-1][j-1]=2;
                    }
                }
                if(j+1<m)
                {
                    if(board[i][j+1]==0)board[i][j+1]=2;
                    if(i-1>=0)
                    {
                        if(board[i-1][j+1]==0)board[i-1][j+1]=2;
                    }
                }
                if(j-1>=0)
                {
                    if(board[i][j-1]==0)board[i][j-1]=2;
                    if(i+1<n)
                    {
                        if(board[i+1][j-1]==0)board[i+1][j-1]=2;
                    }
                }
            }
        }
    }
    int brh=0,brv=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]==0)
            {
                bool p=false;
                for(int a=0;a<k;a++)
                {
                    if(board[i][j+a]!=0 || j+a>=m)
                    {
                        p=true;
                        if(j+a>=m)
                        {
                            j=0;
                            i++;
                        }
                        else
                        {
                            j=j+a;
                        }
                        break;
                    }
                }
                if(p==false)
                {
                    brh++;
                }
                p=false;
                for(int a=0;a<k;a++)
                {
                    if(board[i+a][j]!=0 || i+a>=n)
                    {
                        p=true;
                        break;
                    }
                }
                if(p==false)
                {
                    brv++;
                }
            }
        }
    }
    cout<<brh<<" "<<brv<<endl;
    return 0;
}
