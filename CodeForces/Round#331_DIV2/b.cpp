#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 200005;

long long n, b[maxN], curr, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    curr = b[0];
    if(b[0] != 0) ans += abs(b[
                             0]);
    for(int i = 1; i < n; i++)
    {
        if(b[i] - curr != 0) ans += abs(b[i] - curr);
        curr += b[i] - curr;
    }

    cout<<ans<<endl;
    return 0;
}
