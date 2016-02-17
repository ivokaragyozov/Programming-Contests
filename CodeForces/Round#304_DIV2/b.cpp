#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

long long n, a[3005], ans=0, mina=1<<31-1, maxa=0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mina=min(mina, a[i]);
        maxa=max(maxa, a[i]);
    }
}
void output()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<ans<<endl;
}

int main()
{
    input();
    sort(a, a+n);
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    maxa=max(maxa, mina+n-1);
    for(int i=maxa, j=n-1; j>=0; i--, j--)
    {
        cout<<i<<" "<<a[j]<<endl;
        ans+=i-a[j];
    }
    output();
    return 0;
}
