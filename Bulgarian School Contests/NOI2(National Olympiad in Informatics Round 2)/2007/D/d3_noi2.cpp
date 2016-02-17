/**
Ivo Karagyozov
NOI2 2007 D3 d3
*/
#include<iostream>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int a[205][205];
    int minx=25005,maxx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]<minx && a[i][j]>=x)minx=a[i][j];
            if(a[i][j]>maxx)maxx=a[i][j];
        }
        if(i!=n-1)
        {
            x=minx;
            if(x==25005)
            {
                x=maxx;
                minx=maxx;
            }
            cout<<minx<<" ";
            minx=25005;
            maxx=0;
        }
    }
    if(minx==25005)minx=maxx;
    cout<<minx<<endl;
    return 0;
}
