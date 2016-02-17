#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 3e5 + 5;

int n, m, a, currSum, lastSum, ans;
queue<int> window;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        currSum += a;
        window.push(a);

        while(currSum > m)
        {
            currSum -= window.front();
            window.pop();
        }

        if(currSum > ans) ans = currSum;
    }

    cout<<ans<<endl;
    return 0;
}
