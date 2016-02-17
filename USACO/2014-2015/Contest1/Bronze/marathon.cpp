/**
Ivo Karagyozov
5/15 correct
*/
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int n, x[100005], y[100005], d[100005][2], kir, maxkir, ind, sum=0;

int main()
{
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
        if(i!=0)
        {
            d[i][0]=abs(x[i-1]-x[i])+abs(y[i-1]-y[i]);
        }
        if(i>1)
        {
            d[i][1]=abs(x[i-2]-x[i])+abs(y[i-2]-y[i]);
        }
    }
    for(int i=1; i<n-1; i++)
    {
        kir=(d[i][0]+d[i+1][0])-d[i][1];
        if(kir>maxkir)
        {
            maxkir=kir;
            ind=i;
        }
    }
    bool p=false;
    for(int i=1; i<n; i++)
    {
        if(i!=ind)
        {
            if(p==false)sum+=d[i][0];
            else
            {
                sum+=d[i][1];
                p=false;
            }
        }
        else p=true;
    }
    cout<<sum<<endl;
    return 0;
}
