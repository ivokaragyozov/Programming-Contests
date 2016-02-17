/**
Ivo Karagyozov
NOI3 2011 D1 word
*/
#include<iostream>
using namespace std;
bool isprav(string s)
{
    if(s.size()%2==0)return false;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]>='A' && s[i]<='Z')s[i]=s[i]+('a'-'A');
        if(s[i-1]>s[i])return false;
    }
    return true;
}
int main()
{
    string s,t;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='*')
        {
            t=t+' ';
        }
        else if(s[i]!='%' && s[i]!='=' && s[i]!='+' && s[i]!='-' && s[i]!='(' && s[i]!=')' && s[i]!=':' && s[i]!='.' && s[i]!=',')
        {
            t=t+s[i];
        }
    }
    int brd=0,nom=0,maxs=0;
    for(int i=0;i<t.size();)
    {
        string t1="";
        while((t[i]<='Z' && t[i]>='A') || (t[i]<='z' && t[i]>='a'))
        {
            t1=t1+t[i];
            i++;
            if(i==t.size())break;
        }
        brd++;
        if(isprav(t1))
        {
            if(t1.size()>maxs)
            {
                maxs=t1.size();
                nom=brd;
            }
        }
        if(i==t.size())break;
        while(!((t[i]<='Z' && t[i]>='A') || (t[i]<='z' && t[i]>='a')))i++;
    }
    cout<<nom<<" "<<maxs<<endl;
    return 0;
}
