#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

long long n, w, cups[200005];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>w;
    for(int i=0; i<2*n; i++)
    {
        cin>>cups[i];
    }
}

int main()
{
    input();
    sort(cups, cups+2*n);
    double boys, girls = cups[0];
    boys = 2*girls;
    if(boys > cups[n])
    {
        boys = cups[n];
        girls = boys/2.0;
    }
    double ans = boys*n+girls*n;
    if(ans <= w)cout<<ans<<endl;
    else
    {
        cout<<w<<endl;
    }
    return 0;
}

