#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int m1, m2, m3, m4, m5, w1, w2, w3, w4, w5, ans, hs, hu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m1>>m2>>m3>>m4>>m5>>w1>>w2>>w3>>w4>>w5>>hs>>hu;

    ans = max((double)150, (double)(1.0 - (m1 / 250.0)) * 500 - 50 * w1);
    ans += max((double)300, (double)(1.0 - (m2 / 250.0)) * 1000 - 50 * w2);
    ans += max((double)450, (double)(1.0 - (m3 / 250.0)) * 1500 - 50 * w3);
    ans += max((double)600, (double)(1.0 - (m4 / 250.0)) * 2000 - 50 * w4);
    ans += max((double)750, (double)(1.0 - (m5 / 250.0)) * 2500 - 50 * w5);
    ans += 100 * hs;
    ans -= 50 * hu;

    cout<<ans<<endl;
    return 0;
}
