/**
Ivo Karagyozov
NOI3 2015 C5 guess
*/
#include<iostream>
#include<algorithm>
using namespace std;

int n, maxy=0, nod=1, ans[10005], ind=0;

int gcd(int a, int b)
{
    while(b>0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x, y, r;
        cin>>x>>y;
        r=x-y;
        if(i==0)nod=r;
        else nod=gcd(nod, r);
        if(y>maxy)maxy=y;
    }
    for(int i=1; i*i<=nod; i++)
    {
        if(nod%i==0)
        {
            if(i>maxy)
            {
                ans[ind]=i;
                ind++;
            }
            if(nod/i>maxy && nod/i!=i)
            {
                ans[ind]=nod/i;
                ind++;
            }
        }
    }
    sort(ans, ans+ind);
    cout<<ind<<endl;
    if(ind==0)return 0;
    for(int i=0; i<ind-1; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<ans[ind-1]<<endl;
    return 0;
}
