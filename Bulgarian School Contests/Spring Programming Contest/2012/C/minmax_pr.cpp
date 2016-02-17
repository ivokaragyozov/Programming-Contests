/**
Ivo Karagyozov
Proleten 2012 C2 minmax
*/
#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

int n, c, a[20], b[20];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>c;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
}
string intToStr(int k)
{
    string s;
    while(k>0)
    {
        s+=(char)(k%10+'0');
        k/=10;
    }
    reverse(s.begin(), s.end());
    return s;
}
string add(string s, int k)
{
    string t=intToStr(k), r, p;
    int prenos=0;

    if(s.size()<t.size())swap(s, t);
    r.resize(s.size(), '0');
    p.resize(s.size()-t.size(), '0');
    t=p+t;
    for(int i=s.size()-1; i>=0; i--)
    {
        int tmp=(s[i]-'0')+(t[i]-'0')+prenos;
        prenos=tmp/10;
        tmp%=10;
        r[i]=(char)(tmp+'0');
    }
    if(prenos)
    {
        r='1'+r;
    }
    return r;
}
string sub(string s, int k)
{
    string t=intToStr(k), r, p;
    int prenos=0;

    if(s.size()<t.size())swap(s, t);
    r.resize(s.size(), '0');
    p.resize(s.size()-t.size(), '0');
    t=p+t;
    for(int i=s.size()-1; i>=0; i--)
    {
        int tmp=(s[i]-'0')-(t[i]-'0')-prenos;
        if(tmp<0)
        {
            tmp+=10;
            prenos=1;
        }
        else prenos=0;
        r[i]=(char)(tmp+'0');
    }
    return r;
}
string multi(string s1, int k)
{
    string s2=intToStr(k), r;
    int pp;

    r.resize(s1.size()+s2.size()+1,'0');
    pp=r.size()-1;
    for(int i=s2.size()-1;i>=0;i--)
    {
        int prenos=0,p=pp;
        for(int j=s1.size()-1;j>=0;j--)
        {
            int tmp=(s1[j]-'0')*(s2[i]-'0')+prenos+(r[p]-'0');
            r[p]=(char)(tmp%10+'0');
            prenos=tmp/10;
            p--;
        }
        if(prenos)r[p]=(char)(prenos+'0');
        pp--;
    }
    int i;
    for(i=0;r[i]=='0';i++);
    r=r.substr(i,r.size()-i);
    return r;
}

int main()
{
    input();
    string sMin=intToStr(c), sMax=sMin;
    for(int i=n-1; i>=0; i--)
    {
        sMin=sub(sMin, b[i]);
        sMax=sub(sMax, b[i]);
        sMin=multi(sMin, a[i]);
        sMax=multi(sMax, a[i]);
        sMax=add(sMax, a[i]-1);
    }
    cout<<sMin<<" "<<sMax<<endl;
    return 0;
}
