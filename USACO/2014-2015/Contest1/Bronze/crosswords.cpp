/**
Ivo Karagyozov
9/10 correct
*/
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

struct field
{
    int i, j;
    field(int a, int b)
    {
        i=a;
        j=b;
    }
};

int n, m;
char board[55][55];
vector<field> v;

int main()
{
    freopen("crosswords.in", "r", stdin);
    freopen("crosswords.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j]=='.' && (((i-1<0 || board[i-1][j]=='#') && (i+2<n && board[i+1][j]=='.' && board[i+2][j]=='.')) || ((j-1<0 || board[i][j-1]=='#') && (j+2<n && board[i][j+1]=='.' && board[i][j+2]=='.'))))
            {
                v.push_back(field(i+1, j+1));
            }
        }
    }
    cout<<v.size()<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].i<<" "<<v[i].j<<endl;
    }
    return 0;
}
