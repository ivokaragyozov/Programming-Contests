#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

int t, n, a, ans;
string bins[maxN];

string toBin(int n)
{
    string s;
    while(n != 0)
    {
        s = s + (char)(n % 2 + '0');
        n /= 2;
    }

    reverse(s.begin(), s.end());
    return s;
}
int dist(string s, string t)
{
    if(s.size() > t.size()) swap(s, t);
    string r;
    r.resize(t.size() - s.size(), '0');
    s = r + s;

    int a = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != t[i]) a++;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n;
        ans = 0;

        for(int i = 0; i < n; i++)
        {
            cin>>a;

            bins[i] = toBin(a);

            for(int j = i - 1; j >= 0; j--)
            {
                int d = dist(bins[i], bins[j]);

                if(d > ans) ans = d;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
