/**
Ivo Karagyozov
Proleten 2014 C2 transformations
*/
#include<iostream>
#include<algorithm>
using namespace std;

string dyn[1005], br1="1";

string sum(string s, string t)
{
    if(t.size()>s.size())swap(s, t);

    reverse(t.begin(), t.end());
    t.resize(s.size(), '0');
    reverse(t.begin(), t.end());

    string ans;
    ans.resize(s.size(), '0');

    int naum=0;
    for(int i=s.size()-1; i>=0; i--)
    {
        int tmp=(s[i]-'0')+(t[i]-'0')+naum;
        naum=tmp/10;
        tmp=tmp%10;
        ans[i]=(char)(tmp+'0');
    }
    if(naum>0)
    {
        ans="1"+ans;
    }
    return ans;
}

string multi(string s)
{
    string ans;
    ans.resize(s.size(), '0');

    int naum=0;
    for(int i=s.size()-1; i>=0; i--)
    {
        int tmp=(s[i]-'0')*2+naum;
        naum=tmp/10;
        tmp=tmp%10;
        ans[i]=(char)(tmp+'0');
    }
    if(naum>0)
    {
        ans="1"+ans;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    dyn[0]="0";
    dyn[1]="0";
    dyn[2]="0";
    for(int i=3; i<=n; i++)
    {
        dyn[i]=sum(dyn[i-2], br1);
        br1=multi(br1);
    }
    cout<<dyn[n]<<endl;
    return 0;
}
