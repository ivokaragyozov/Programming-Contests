#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int d1, d2, d3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>d1>>d2>>d3;

    int val1 = d1 + d3 + d2, val2 = 2 * d1 + 2 * d3, val3 = 2 * d2 + 2 * d3, val4 = 2 * d1 + 2 * d2;
    cout<<min(val1, min(val2, min(val3, val4)))<<endl;
    return 0;
}
