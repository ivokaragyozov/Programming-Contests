/**
Ivo Karagyozov
Proleten 2015 C1 lg
*/
#include <iostream>
#define endl '\n'
using namespace std;

string a, b, number="1";

string multi(string s, string t)
{
    string r;
    int prenos=0, tmp, pp, p;
    r.resize(s.size()+t.size()+1, '0');
    pp=r.size()-1;
    for(int i=s.size()-1; i>=0; i--)
    {
        p=pp;
        for(int j=t.size()-1; j>=0; j--)
        {
            tmp=(s[i]-'0')*(t[j]-'0')+(r[p]-'0')+prenos;
            r[p]=(char)(tmp%10+'0');
            prenos=tmp/10;
            p--;
        }
        if(prenos)
        {
            r[p]=(char)(prenos+'0');
            prenos=0;
        }
        pp--;
    }
    int i=0;
    for(; r[i]=='0'; i++);
    return r.substr(i);
}
bool cmp(string s, string t)
{
    if(s.size()!=t.size())
    {
        return s.size()>t.size();
    }
    return s>=t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b;
    for(int k=1; k<=400; k++)
    {
        number=multi(number, b);
        if(!cmp(a, number))
        {
            cout<<k-1<<endl;
            return 0;
        }
    }
    return 0;
}
