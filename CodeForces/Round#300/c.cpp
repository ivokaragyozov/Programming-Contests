#include<iostream>
#include<cmath>
using namespace std;

long long n, m, d, h, ld=1, lh=0, ans=0, bd, bh;
bool p=false;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>d>>h;
        if(h>ans)ans=h;
        if(i==0)
        {
            bd=d;
            bh=h;
            ld=d;
            lh=h;
            continue;
        }
        long long maxd=(d-ld-1)/2+max(h, lh);

        if(d-ld<abs(h-lh))
        {
            p=true;
        }
        if(maxd>ans)ans=maxd;
        ld=d;
        lh=h;
    }
    if(p)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    if(bd-1+bh>ans)ans=bd+bh-1;
    if(n-d+h>ans)ans=n-d+h;
    cout<<ans<<endl;
    return 0;
}
