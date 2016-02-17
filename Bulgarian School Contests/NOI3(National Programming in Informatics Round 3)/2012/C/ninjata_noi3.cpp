/**
Ivo Karagyozov
NOI3 2012 C2 ninjata
*/
#include <iostream>
#define endl '\n'
using namespace std;

int n, table[15][15], answer = 1<<30;

void bfs(int i, int j, int cntSeconds)
{
    if(table[i][j] == 1 && cntSeconds%2 != 0) return;
    if(table[i][j] == 0 && cntSeconds%2 == 0) return;

    if(i == n-1 && j == n-1)
    {
        if(cntSeconds < answer)
        {
            answer = cntSeconds;
        }
        return;
    }

    if(i+1 < n)
    {
        bfs(i+1, j, cntSeconds+1);
        bfs(i+1, j, cntSeconds+2);
    }
    if(j+1 < n)
    {
        bfs(i, j+1, cntSeconds+1);
        bfs(i, j+1, cntSeconds+2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>table[i][j];
        }
    }
    bfs(0, 0, 1);
    cout<<answer<<endl;
    return 0;
}
