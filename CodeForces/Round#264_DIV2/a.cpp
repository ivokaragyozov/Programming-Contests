#include <iostream>
#define endl '\n'
using namespace std;

int n, s, x, y, maxCntCandies = -1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>s;
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        if((x < s || (x == s && y == 0)) && maxCntCandies < (100-y)%100) maxCntCandies = (100-y)%100;
    }

    cout<<maxCntCandies<<endl;
    return 0;
}
