/**
Ivo Karagyozov
Proleten 2014 C3 stars
*/
#include<iostream>
#include<cstring>
using namespace std;

int n, m, t, k1, k2, a[25005]={1};
long long ans=0;

void buildLine(int p)
{
    for(int i=0; i<p; i++)
    {
        a[i]=1;
        a[0]=1;
        for(int j=i-1; j>=0; j--)
        {
            a[j]=(a[j-1]+a[j])%m;
        }
    }
}

int main()
{
    cout<<(0^1)<<endl;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>t;
    buildLine(n);
    for(int i=0; i<t; i++)
    {
        cin>>k1>>k2;
        for(int j=k1; j<=k2; j++)
        {
            ans+=a[j]%m;
        }
        if(ans%m==0)ans=m;
        else ans%=m;
        if(i!=t-1)cout<<ans<<" ";
        else cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
