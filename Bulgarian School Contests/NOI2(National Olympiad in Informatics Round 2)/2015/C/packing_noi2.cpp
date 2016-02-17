/**
Ivo Karagyozov
NOI2 2015 C2 packing
*/
#include<iostream>
#include<cstdio>
using namespace std;

int n;
string s[130], t="";

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    t=s[0];
    for(int i=1; i<n; i++)
    {
        int beg;
        if(s[i].size()>=s[i-1].size())
        {
            beg=1;
        }
        else
        {
            beg=s[i-1].size()-s[i].size()+1;
        }
        bool p=false;
        for(int j=beg; j<s[i-1].size(); j++)
        {
            string a=s[i-1].substr(j);
            string b=s[i].substr(0, a.size());
            if(a==b)
            {
                p=true;
                t+=s[i].substr(a.size());
                break;
            }
        }
        if(p==false)t+=s[i];
    }
    cout<<t<<endl;
    return 0;
}
