/**
Ivo Karagyozov
Proleten 2014 D2 fina
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct competitor
{
    string country;
    string sname;
    string name;
    string r[20];
};
int n,m,l;
int cmp(competitor s,competitor t)
{
    int j=0;
    while(1)
    {
        if(j==m)break;
        if(s.r[j]!=t.r[j])return s.r[j]<t.r[j];
        j++;
    }
    return s.country<t.country;
}
int cmp1(string s,string t)
{
    if(s.size()!=t.size())return s.size()<t.size();
    else return s<t;
}
competitor t[260];
int main()
{
    char a;
    cin>>n>>m>>l;
    cin.get(a);
    bool p=false;
    string s;
    for(int i=0;i<n;i++)
    {
        t[i].country = "";
        t[i].name = "";
        t[i].sname = "";

        getline(cin,s);
        int br=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]!=' ')
            {
                if(br==0)t[i].country+=s[j];
                else if(br==1)t[i].sname+=s[j];
                else if(br==2)t[i].name+=s[j];
                else
                {
                    t[i].r[br-3]+=s[j];
                    if(s[j]!='x')p=true;
                }
            }
            else
            {
                if(br>=3 && t[i].r[br-3]=="x")t[i].r[br-3]="10000000000";
                if(s[j-1]!=' ')br++;

            }
        }
        if(t[i].r[br-3]=="x")t[i].r[br-3]="10000000000";
    }
    if(p==false)
    {
        cout<<"No results!"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        sort(t[i].r,t[i].r+m,cmp1);
    }
    sort(t,t+n,cmp);
    int pos=1,j=0;
    bool k=false;
    for(int i=0;i<l;i++)
    {
        cout<<pos<<". ";
        while(1)
        {
            cout<<t[j].country<<" "<<t[j].sname<<" "<<t[j].name<<" "<<t[j].r[0]<<endl;
            j++;
            if(j==n)
            {
                k=true;
                break;
            }
            pos++;
            if(t[j].r[0]!=t[j-1].r[0])break;

        }
        if(k==true)break;
    }
    return 0;
}
