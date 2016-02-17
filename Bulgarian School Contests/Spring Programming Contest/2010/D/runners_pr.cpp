/**
Ivo Karagyozov
Proleten 2010 D1 runners
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10005;
int s[N],p[N],t[N],laps[N],times[1000005];
int main()
{
    int k,n;
    cin>>k>>n;
    for(int i=0;i<k;i++)
    {
        cin>>s[i]>>p[i];
        laps[i]=s[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            t[j]=t[j]+laps[j];
            laps[j]++;
            if(i%p[j]==0)laps[j]=s[j];
            times[t[j]]++;
        }
    }
    sort(times,times+N);
    cout<<times[N-1]<<endl;
    return 0;
}
