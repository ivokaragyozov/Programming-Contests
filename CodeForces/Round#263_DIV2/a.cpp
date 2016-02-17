#include <iostream>
#define endl '\n'
using namespace std;

int n;
char table[105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>table[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int cnt = 0;
            if(i > 0 && table[i-1][j] == 'o') cnt++;
            if(j < n-1 && table[i][j+1] == 'o') cnt++;
            if(i < n-1 && table[i+1][j] == 'o') cnt++;
            if(j > 0 && table[i][j-1] == 'o') cnt++;
            if(cnt%2 != 0)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
