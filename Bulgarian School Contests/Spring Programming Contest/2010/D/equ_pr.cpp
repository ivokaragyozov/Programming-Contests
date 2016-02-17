/**
Ivo Karagyozov
Proleten 2010 D2 equ
*/
#include<iostream>
using namespace std;
string sum(string s1,string s2,int p)
{
    string r;
    if(s1.size()<s2.size())swap(s1,s2);
    r=s1;
    string s;
    s.resize(s1.size()-s2.size(),'0');
    s2=s+s2;
    int prenos=0;
    for(int i=s2.size()-1;i>=0;i--)
    {
        int tmp=(s2[i]-'0')+(r[i]-'0');
        if(prenos==1)tmp++;
        r[i]=(char)(tmp%p+'0');
        prenos=tmp/p;
    }
    if(prenos==1)
    {
        r='1'+r;
    }
    return r;
}
string multi(string s1,string s2,int q)
{
    string r;
    r.resize(s1.size()+s2.size()+1,'0');
    int pp=r.size()-1;
    for(int i=s2.size()-1;i>=0;i--)
    {
        int p=pp,prenos=0;
        for(int j=s1.size()-1;j>=0;j--)
        {
            int tmp=((s2[i]-'0')*(s1[j]-'0'))+prenos+(r[p]-'0');
            r[p]=(char)(tmp%q+'0');
            prenos=tmp/q;
            p--;
        }
        if(prenos==2)
        {
            r[p]='0';
            r[p-1]='1';
        }
        else if(prenos==1)
        {
            r[p]='1';
        }
        pp--;
    }
    int i=0;
    for(i=0;r[i]=='0';i++);
    r=r.substr(i,r.size()-i);
    return r;
}
int main()
{
    string s1,s2,s3;
    cin>>s1;
    char a,z;
    while(a==' ')cin>>a;
    cin>>z;
    while(a==' ')cin>>a;
    cin>>s2;
    while(a==' ')cin>>a;
    cin>>a;
    while(a==' ')cin>>a;
    cin>>s3;
    int otg[15],j=0;
    int mind=9;
    for(int i=0;i<s1.size();i++)
    {
        int a=s1[i]-'0';
        if(a<mind)mind=a;
    }
    for(int i=0;i<s2.size();i++)
    {
        int a=s2[i]-'0';
        if(a<mind)mind=a;
    }
    for(int i=0;i<s3.size();i++)
    {
        int a=s3[i]-'0';
        if(a<mind)mind=a;
    }
    if(z=='+')
    {
        for(int i=mind+1;i<=10;i++)
        {
            if(sum(s1,s2,i)==s3)
            {
                otg[j]=i;
                j++;
            }
        }
    }
    else if(z=='*')
    {
        for(int i=mind+1;i<=10;i++)
        {
            if(multi(s1,s2,i)==s3)
            {
                otg[j]=i;
                j++;
            }
        }
    }
    for(int i=0;i<j-1;i++)
    {
        cout<<otg[i]<<" ";
    }
    cout<<otg[j-1]<<endl;
    return 0;
}
