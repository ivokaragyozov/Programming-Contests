#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1005, maxM = 1005;

bool used[maxN][maxM], used2[maxN][maxM];
char table[maxN][maxM];
int n, m, curr = 1, currCnt, currAns = 1, cells[maxN][maxM], cnt[maxN * maxM];

void dfs(int i, int j)
{
    used[i][j] = 1;
    cells[i][j] = curr;
    currCnt++;

    if(i > 0 && !used[i - 1][j] && table[i - 1][j] == '.') dfs(i - 1, j);
    if(j < m - 1 && !used[i][j + 1] && table[i][j + 1] == '.') dfs(i, j + 1);
    if(i < n - 1 && !used[i + 1][j] && table[i + 1][j] == '.') dfs(i + 1, j);
    if(j > 0 && !used[i][j - 1] && table[i][j - 1] == '.') dfs(i, j - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>table[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!used[i][j] && table[i][j] == '.')
            {
                dfs(i, j);
                cnt[curr] = currCnt;
                curr++;
                currCnt = 0;
            }
        }
    }

    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout<<cells[i][j].cnt<<" ";
        }
        cout<<endl;
    }*/


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(table[i][j] == '.') cout<<'.';
            else
            {
                if(i - 1 >= 0 && table[i - 1][j] == '.')
                {
                    if((j + 1 >= m || cells[i][j + 1] != cells[i - 1][j]) && (i + 1 >= n || cells[i + 1][j] != cells[i - 1][j]) && (j - 1 < 0 || cells[i][j - 1] != cells[i - 1][j]))currAns += cnt[cells[i - 1][j]];
                }
                if(j + 1 < m && table[i][j + 1] == '.')
                {
                    if((i + 1 >= n || cells[i + 1][j] != cells[i][j + 1]) && (j - 1 < 0 || cells[i][j - 1] != cells[i][j + 1])) currAns += cnt[cells[i][j + 1]];
                }
                if(i + 1 < n && table[i + 1][j] == '.')
                {
                    if(j - 1 < 0 || cells[i][j - 1] != cells[i + 1][j]) currAns += cnt[cells[i + 1][j]];
                }
                if(j - 1 >= 0 && table[i][j - 1] == '.')
                {
                    currAns += cnt[cells[i][j - 1]];
                }

                cout<<currAns % 10;
                currAns = 1;
            }
        }
        cout<<endl;
    }

    return 0;
}
