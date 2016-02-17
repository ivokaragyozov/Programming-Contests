#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int a[1005], ind=0, n, l;
double dist[1005];
int main()
{
    cin>>n>>l;
    for(int i=0; i<n; i++)cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            dist[ind]=(double)(a[i]);
            ind++;
        }
        else
        {
            dist[ind]=(a[i]-a[i-1])/2.0;
            ind++;
        }
    }
    dist[ind]=(double)(l-a[n-1]);
    ind++;
    sort(dist, dist+ind);
    cout<<fixed<<setprecision(9)<<dist[ind-1]<<endl;
    return 0;
}
