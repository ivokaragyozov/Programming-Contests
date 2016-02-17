/**
Ivo Karagyozov
NOI3 2014 D1 kolan
*/
#include<iostream>
#include<algorithm>
using namespace std;
string num(string s)
{
    int br=0;
    string number="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            number=number+(char)(br+'0');
            br=0;
        }
        else br++;
    }
    number=number+(char)(br+'0');
    return number;
}
int main()
{
    string s,t;
    cin>>s;
    t=s;
    reverse(t.begin(),t.end());
    int sizes=s.size();
    bool p=false;
    int br=0;
    for(int i=0;i<sizes-1;i++)
    {
        if(s[i]=='1')
        {
            if(p==false)p=true;
            else if(i!=0)
            {
                s[i-1]='0';
                br=0;
            }
        }
        s[i]='1';
        br++;
        if(br==11)
        {
            s[i-1]='0';
            br=1;
            p=false;
        }
    }
    if(s[s.size()-1]=='1' && s[s.size()-3]=='1')s[s.size()-2]='0';
    else s[s.size()-1]='1';
    p=false;
    br=0;
    for(int i=0;i<sizes-1;i++)
    {
        if(t[i]=='1')
        {
            if(p==false)p=true;
            else if(i!=0)
            {
                t[i-1]='0';
                br=0;
            }
        }
        t[i]='1';
        br++;
        if(br==11)
        {
            t[i-1]='0';
            br=1;
            p=false;
        }
    }
    if(t[t.size()-1]=='1')t[t.size()-2]='0';
    else t[t.size()-1]='1';
    reverse(t.begin(),t.end());
    cout<<t<<endl;
    cout<<num(s)<<endl<<num(t)<<endl;
    return 0;
}
