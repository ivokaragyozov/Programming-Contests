/**
Ivo Karagyozov
Proleten 2011 C1 game
*/
#include <iostream>
#define endl '\n'
using namespace std;

int s, p, m, n, a[205], b[205];
bool player1[1000005], player2[1000005], k;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>p>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }
}

int main()
{
    input();
    for(int i=1; i<=s; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-a[j]>=0 && player2[i-a[j]]==0)
            {
                player1[i]=1;
                break;
            }
        }
        for(int j=0; j<m; j++)
        {
            if(i-b[j]>=0 && player1[i-b[j]]==0)
            {
                player2[i]=1;
                break;
            }
        }
    }
    if(p==1)
    {
        cout<<player1[s]<<endl;
    }
    else
    {
        cout<<player2[s]<<endl;
    }
    return 0;
}
