/**
Ivo Karagyozov
NOI3 2015 C6 segments
*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct point
{
    long long x;
    int vid;
    point(){}
    point(long long a, int b)
    {
        x=a;
        vid=b;
    }
};

int n, ind=0;
char br1, br2;
long long a, b, c, d, brt=0, ans=0, be=0, en=0;
bool p=false, p1, p2;
double x, y;
point arr[400005];

bool cmp(point a, point b)
{
    if(a.x!=b.x)return a.x<b.x;
    return a.vid<b.vid;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        p1=false;
        p2=false;
        cin>>br1>>a>>b>>c>>d>>br2;
        if(a%b!=0)p1=true;
        if(c%d!=0)p2=true;
        x=(double)a/(double)b;
        y=(double)c/(double)d;
        if(br1=='(')
        {
            if(p1)
            {
                x=ceil(x);
            }
            else
            {
                x++;
            }
        }
        else
        {
            x=ceil(x);
        }
        if(br2==')')
        {
            if(p2)
            {
                y=floor(y);
            }
            else
            {
                y--;
            }
        }
        else
        {
            y=floor(y);
        }
        if(x<=y)
        {
            arr[ind]=point(x, 1);
            ind++;
            arr[ind]=point(y, 2);
            ind++;
        }
    }
    sort(arr, arr+ind, cmp);
    be=arr[0].x;
    en=be;
    brt=1;
    for(int i=1; i<ind; i++)
    {
        if(brt==0)
        {
            ans+=(en-be+1);
            p=true;
        }
        if(arr[i].vid==1)brt++;
        else brt--;
        en=arr[i].x;
        if(p==true)
        {
            be=arr[i].x;
            p=false;
        }
    }
    ans+=(en-be+1);
    cout<<ans<<endl;
    return 0;
}
