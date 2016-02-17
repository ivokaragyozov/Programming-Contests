/**
Ivo Karagyozov
NOI2 2014 D1 barray
*/
#include<iostream>
using namespace std;
const int N=100005;
long long a[N],sum[N];
int main()
{
    int n;
    cin>>n;
    long long s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s=s+a[i];
        sum[i]=s;
    }
    for(int i=0;i<n;i++)
    {
        if(sum[i]==s-sum[i])
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
