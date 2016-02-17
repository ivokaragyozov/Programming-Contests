/**
Ivo Karagyozov
NOI3 2014 C5 jumps
*/
#include<iostream>
using namespace std;

const int MIN_VAL=-(1<<31-1);

int n, a[100005], dyn[100005][2], maxsum=MIN_VAL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    dyn[0][0]=a[0];
    dyn[0][1]=a[0];
    maxsum=a[0];
    for(int i=1; i<n; i++)
    {
        dyn[i][0]=max(dyn[i-1][0], dyn[i-1][1])+a[i];
        if(i>1)dyn[i][1]=dyn[i-2][0]+a[i];
        else dyn[i][1]=MIN_VAL;
        if(maxsum<dyn[i][0])maxsum=dyn[i][0];
        if(maxsum<dyn[i][1])maxsum=dyn[i][1];
    }
    cout<<maxsum<<endl;
    return 0;
}
