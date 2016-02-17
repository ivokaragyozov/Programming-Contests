#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

int n, m, a, b, recognitions[4005], answer = INT_MAX;
bool matrix[4005][4005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
        recognitions[a]++;
        recognitions[b]++;
    }

    for(int i = 1; i <= n-2; i++)
    {
        for(int j = i+1; j <= n-1; j++)
        {
            if(!matrix[i][j]) continue;
            for(int k = j+1; k <= n; k++)
            {
                if(matrix[i][j] && matrix[i][k] && matrix[j][k] && recognitions[i]+recognitions[j]+recognitions[k]-6 < answer) answer = recognitions[i]+recognitions[j]+recognitions[k]-6;
            }
        }
    }

    cout<<(answer != INT_MAX ? answer : -1)<<endl;
    return 0;
}
