/**
Ivo Karagyozov
Proleten 2008 D2
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct rect
{
    int points=0;
    int tsize;
};
int cmp(rect s, rect t)
{
    if(s.tsize==t.tsize)return s.points>t.points;
    else return s.tsize>t.tsize;
}
int main()
{
    int n;
    cin>>n;
    rect t[15];
    int x1[15],y1[15],x2[15],y2[15];
    for(int i=0;i<n;i++)
    {
        bool p=false;
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        int len=x2[i]-x1[i];
        int h=y2[i]-y1[i];
        if((x1<0 && x2>0) || (y1<0 && y2>0))p=true;
        if(p==true)
        {
            t[i].tsize=len/3*2*h;
        }
        else
        {
            t[i].tsize=len/2*h;
        }
    }
    int m;
    cin>>m;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        for(int j=0;j<n;j++)
        {
            if(x>=x1[j] && x<=x2[j] && y>=y1[j] && y<=y2[j])
            {
                t[j].points++;
            }
        }
    }
    sort(t,t+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<t[i].points<<endl;
    }
    return 0;
}
