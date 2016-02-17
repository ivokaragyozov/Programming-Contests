#include <iostream>
#define endl '\n'
using namespace std;

int m, c[105], sum, curBeginnerGroup, x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>c[i];
        sum += c[i];
    }

    cin>>x>>y;

    for(int i = 0; i < m; i++)
    {
        curBeginnerGroup += c[i];
        if(curBeginnerGroup >= x && curBeginnerGroup <= y && (sum-curBeginnerGroup) >= x && (sum-curBeginnerGroup) <= y)
        {
            cout<<i+2<<endl;
            return 0;
        }
    }

    cout<<0<<endl;
    return 0;
}
