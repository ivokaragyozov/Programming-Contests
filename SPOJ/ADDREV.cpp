#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long t, a, b;

long long reverseNum(long long p)
{
    long long reversedNum = 0;
    while(p > 0)
    {
        reversedNum = reversedNum * 10 + p % 10;
        p /= 10;
    }

    return reversedNum;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>a>>b;

        cout<<reverseNum(reverseNum(a) + reverseNum(b))<<endl;
    }

    return 0;
}
