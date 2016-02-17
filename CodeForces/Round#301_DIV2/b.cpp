#include<iostream>
using namespace std;

int n, k, p, x, y, sum=0, maxsum=0, ans[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k>>p>>x>>y;
    maxsum=n*p;
    for(int i=0; i<k; i++)
    {
        int a;
        cin>>a;
        sum+=a;
    }
    int need=x-sum;
    int med=(n+1)/2;
    if(need<0 || (n-k)*p<need)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=k; i<n-k; i++)
    {
        if(i==med)
        {
            ans[i]=y;
            sum+=y;
        }
        else
        {
            ans[i]=1;
            sum+=i;
        }
        if(i==n-k-1)
        {
            ans[i]=p;
        }
    }
}
