/**
Ivo Karagyozov
NOI3 2013 D3 rabbits
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct house
{
    int nom;
    int pos;
};
struct hran
{
    int nom;
    int pos;
};
int f1(house s,house t)
{
    return s.nom<t.nom;
}
int f2(hran s,hran t)
{
    return s.nom<t.nom;
}
int main()
{
    int n;
    cin>>n;
    house t[100005];
    hran s[100005];
    for(int i=0;i<n;i++)
    {
        cin>>t[i].nom;
        t[i].pos=i+1;
    }
    for(int i=0;i<n;i++)
    {
        cin>>s[i].nom;
        s[i].pos=i+1;
    }
    sort(t,t+n,f1);
    sort(s,s+n,f2);
    int maxr=0;
    for(int i=0;i<n;i++)
    {
        if(max(s[i].pos,t[i].pos)-min(s[i].pos,t[i].pos)>maxr)
        {
            maxr=max(s[i].pos,t[i].pos)-min(s[i].pos,t[i].pos);
        }
    }
    cout<<maxr<<endl;
    return 0;
}
