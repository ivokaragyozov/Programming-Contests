#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int y;

bool hasDistinctDigits(int a)
{
    bool digs[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while(a > 0)
    {
        if(digs[a % 10]) return false;
        digs[a % 10] = true;
        a /= 10;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>y;
    for(int i = y + 1; ; i++)
    {
        if(hasDistinctDigits(i))
        {
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}
