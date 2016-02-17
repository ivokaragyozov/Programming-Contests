#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxA = 105;

int t, n, a, cnt[maxA], currMax, indMax;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        memset(cnt, 0, sizeof(cnt));
        currMax = 0;

        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>a;

            cnt[a]++;
        }

        for(int i = 1; i < maxA; i++)
        {
            if(cnt[i] > currMax && cnt[i] % i == 0)
            {
                currMax = cnt[i];
                indMax = i;
            }
        }

        if(currMax == 0) cout<<-1<<endl;
        else cout<<indMax<<endl;
    }

    return 0;
}
