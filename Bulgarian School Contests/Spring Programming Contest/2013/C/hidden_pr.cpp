/**
Ivo Karagyozov
Proleten 2013 C1 hidden
*/
#include<iostream>
#define endl '\n'
using namespace std;

int n, m, k;
char board[55][55];
string words[55];
bool dp[55][55][55][55];

void input()
{
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
    cin>>k;
    for(int i=0; i<k; i++)
    {
        cin>>words[i];
    }
}

int main()
{
    input();
    for(int i=0; i<k; i++)
    {
        bool p=false;
        for(int j=0; j<words[i].size(); j++)
        {
            if(p)break;
            for(int x=0; x<n; x++)
            {
                if(p)break;
                for(int y=0; y<m; y++)
                {
                    if(board[x][y]==words[i][j])
                    {
                        if(j==0)
                        {
                            dp[x][y][i][j]=true;
                            if(j==words[i].size()-1)
                            {
                                p=true;
                                break;
                            }
                        }
                        else
                        {
                            if(x>0 && dp[x-1][y][i][j-1])
                            {
                                dp[x][y][i][j]=true;
                                if(j==words[i].size()-1)
                                {
                                    p=true;
                                    break;
                                }
                            }
                            else if(y<m-1 && dp[x][y+1][i][j-1])
                            {
                                dp[x][y][i][j]=true;
                                if(j==words[i].size()-1)
                                {
                                    p=true;
                                    break;
                                }
                            }
                            else if(x<n-1 && dp[x+1][y][i][j-1])
                            {
                                dp[x][y][i][j]=true;
                                if(j==words[i].size()-1)
                                {
                                    p=true;
                                    break;
                                }
                            }
                            else if(y>0 && dp[x][y-1][i][j-1])
                            {
                                dp[x][y][i][j]=true;
                                if(j==words[i].size()-1)
                                {
                                    p=true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(p)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
/**
5 6
glmnta
csoikf
dgotzf
hcnats
oemcpw
7
nato
god
meh
cat
catod
gg
stanchoemnogogotin
*/
