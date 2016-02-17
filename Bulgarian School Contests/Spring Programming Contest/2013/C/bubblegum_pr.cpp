/**
Ivo Karagyozov
Proleten 2013 C2 bubblegum
*/
#include<iostream>
#define endl '\n'
using namespace std;

int n, t[10005], br=0, dels[1005];
string ans="1";

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>t[i];
    }
}
string intToStr(int a)
{
    string s="";
    while(a>0)
    {
        s=(char)(a%10+'0')+s;
        a/=10;
    }
    return s;
}
string multi(string s1, string s2)
{
    string r;
    r.resize(s1.size()+s2.size()+1,'0');
    int pp=r.size()-1;
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
    for(int i=0; i<n; i++)
    {
        for(int j=2; j*j<=t[i]; j++)
        {
            br=0;
            while(t[i]%j==0)
            {
                t[i]/=j;
                br++;
            }
            if(dels[j]<br)dels[j]=br;
        }
        if(dels[t[i]]==0)dels[t[i]]=1;
    }
    for(int i=2; i<=1000; i++)
    {
        for(int j=0; j<dels[i]
        ; j++)
        {
            ans=multi(ans, intToStr(i));
        }
    }
    cout<<ans<<endl;
    return 0;
}

