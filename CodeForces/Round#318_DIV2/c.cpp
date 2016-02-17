#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

int n, a[100005], b[100005], c;
map<int, int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];

        if(dp[a[i]]) b[i] = dp[a[i]];
        else
        {
            c = a[i];

            while(a[i]%2 == 0) a[i] /= 2;
            while(a[i]%3 == 0) a[i] /= 3;

            b[i] = a[i];
            dp[c] = a[i];
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(b[i-1] != b[i])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
    return 0;
}
