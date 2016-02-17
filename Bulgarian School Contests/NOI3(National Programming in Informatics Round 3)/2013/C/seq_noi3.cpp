#include<iostream>
using namespace std;

int n, raz[1005], a[1000005], maxnum=0, maxraz=0, ans=0, br=0, d=0, lasti=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>maxnum)maxnum=a[i];
    }
    for(int i=0; i<n; i++)
    {
        raz[maxnum-a[i]]++;
        if(maxnum-a[i]>maxraz)maxraz=maxnum-a[i];
    }
    br=raz[0];
    for(int i=1; i<=maxraz; i++)
    {
        ans+=br;
        br+=raz[i];
        if(raz[i]!=0)
        {
            ans-=d;
            d+=i-lasti;
            lasti=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
