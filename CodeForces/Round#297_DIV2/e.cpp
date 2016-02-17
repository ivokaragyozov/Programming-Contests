#include<iostream>
using namespace std;

int a[25];
long long fac[20]={0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000};
int n, k, s;
long long ans=0;

void rec(long long sum, int br, int j)
{
    if(sum==s)
    {
        ans++;
        return;
    }
    if(sum>s)return;
    if(j>=n)return;
    if(br>k)return;
    rec(sum+a[j], br, j+1);
    if(a[j]<20)rec(sum+fac[a[j]], br+1, j+1);
    rec(sum, br, j+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>s;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    rec(a[0], 0, 1);
    if(a[0]<20)rec(fac[a[0]], 1, 1);
    rec(0, 0, 1);
    cout<<ans<<endl;
    return 0;
}
