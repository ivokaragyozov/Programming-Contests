#include<iostream>
#define endl '\n'
using namespace std;

int v1, v2, t, d, res=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>v1>>v2>>t>>d;
    int l=v1, r=v2+d*(t-1);
    for(int i=0; i<t; i++)
    {
        res+=min(l, r);
        l+=d;
        r-=d;
    }
    cout<<res<<endl;
    return 0;
}
