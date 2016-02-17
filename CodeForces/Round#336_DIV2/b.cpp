#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxS = 2e5 + 5;

long long sums[maxS], begInd, endInd, ones, zeros, ans;
string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>t;
    for(int i = 0; i < s.size(); i++)
    {
        if(i == 0) sums[i] = s[i] - '0';
        else sums[i] = sums[i - 1] + (s[i] - '0');
    }


    for(int i = 0; i < t.size(); i++)
    {
        if(i < s.size() - 1) endInd = i;
        else endInd = s.size() - 1;
        if(t.size() - i < s.size()) begInd = s.size() - (t.size() - i);
        else begInd = 0;

        ones = sums[endInd] - (begInd != 0 ? sums[begInd - 1] : 0);
        zeros = endInd - begInd + 1 - ones;

        //cout<<begInd<<" "<<endInd<<" "<<ones<<" "<<zeros<<endl;

        if(t[i] == '1') ans += zeros;
        else ans += ones;
    }

    cout<<ans<<endl;
    return 0;
}
