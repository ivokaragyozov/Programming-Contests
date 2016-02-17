#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 2000;

bool answer = true;
int n, a[maxN + 5][maxN + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>a[i][j];

            if(i == j && a[i][j] != 0)
            {
                answer = false;
            }
        }
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i][j] != a[j][i])
            {
                answer = false;
                break;
            }
        }
    }

    cout<<(answer ? "YES" : "NO")<<endl;
    return 0;
}
