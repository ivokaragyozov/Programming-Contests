#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 1; cs <= t; cs++)
    {
        cin>>a>>b;

        if(a == b) cout<<"Square"<<endl;
        else cout<<"Rectangle"<<endl;
    }

    return 0;
}
