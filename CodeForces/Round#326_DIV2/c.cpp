#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1e6;

int n, a, cnt[5 * maxN], maxA, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        if(a > maxA) maxA = a;

        cnt[a]++;
    }

    for(int i = 0; i <= maxA; i++)
    {
        cnt[i + 1] += cnt[i] / 2;
        cnt[i] %= 2;

        ans += cnt[i];
    }

    int i;
    for(i = maxA + 1; ; i++)
    {
        if(cnt[i] == 0) break;
        if(cnt[i] == 1)
        {
            ans++;
            break;
        }
        cnt[i + 1] += cnt[i] / 2;
        cnt[i] %= 2;

        ans += cnt[i];
    }

    cout<<ans<<endl;
    return 0;
}
