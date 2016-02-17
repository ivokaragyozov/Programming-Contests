/**
Ivo Karagyozov
NOI1 2015 C2 difference
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string minusLongNums(string a, string b)
{
    string ans="";
    ans.resize(a.size(), '0');
    int prenos=0;
    for(int i=b.size()-1; i>=0; i--)
    {
        int num=(a[i]-'0')-(b[i]-'0')-prenos;
        if(num<0)
        {
            num+=10;
            prenos=1;
        }
        else prenos=0;
        ans[i]=(char)(num+'0');
    }
    string s=ans;
    ans="";
    int i=0;
    while(s[i]=='0')i++;
    for(int j=i; j<s.size(); j++)ans=ans+s[j];
    if(ans.size()==0)ans="0";
    return ans;
}
int main()
{
    string num;
    cin>>num;
    string a="", b="";
    sort(num.begin(), num.end());
    b=num;
    if(b[0]=='0')
    {
        for(int i=1; i<b.size(); i++)
        {
            if(b[i]!='0')
            {
                b[0]=b[i];
                b[i]='0';
                break;
            }
        }
    }
    for(int i=num.size()-1; i>=0; i--)a=a+num[i];
    cout<<minusLongNums(a, b)<<endl;
    return 0;
}
