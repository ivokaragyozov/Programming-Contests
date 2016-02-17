#include <iostream>
#define endl '\n'
using namespace std;

int n, m, a[1000006], dp[1000005],cnt[2000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];}
    cnt[0]=1;
    for(int i=0;i<n;i++) {
        if(i>0) a[i]=a[i]+a[i-1];
        a[i]%=m;

        if(cnt[a[i]]) {
            cout<<"YES"<<endl;
            return 0;
        }

        cnt[a[i]]=1;
    }
    cout<<"NO"<<endl;
}
