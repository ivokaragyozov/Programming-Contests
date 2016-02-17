#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 10, maxM = 5e4;

int n, m, t[maxM][maxN], finish[maxM][maxN], maxTime = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>t[i][j];
        }
    }

    finish[0][0] = t[0][0];
    for(int i = 1; i < m; i++) finish[i][0] = finish[i - 1][0] + t[i][0];
    for(int j = 1; j < n; j++) finish[0][j] = finish[0][j - 1] + t[0][j];

    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            finish[i][j] = max(finish[i][j - 1] + t[i][j], finish[i - 1][j] + t[i][j]);
        }
    }

    for(int i = 0; i < m; i++) cout<<finish[i][n - 1]<<" ";
    return 0;
}
