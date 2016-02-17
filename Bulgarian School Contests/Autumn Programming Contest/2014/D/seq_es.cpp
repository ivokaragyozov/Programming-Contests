/**
Ivo Karagyozov
Esenen 2014 D3 seq
*/
#include<iostream>
#include<algorithm>
using namespace std;
string multiLongNum(string s, string x)
{
    string ans="";
    ans.resize(s.size()+x.size()+6, '0');
    int pp=ans.size()-1;
    int prenos=0;
    for(int i=x.size()-1; i>=0; i--)
    {
        int p=pp;
        prenos=0;
        for(int j=s.size()-1; j>=0; j--)
        {
            int sum=(s[j]-'0')*(x[i]-'0')+prenos;
            int tmp=sum+(ans[p]-'0');
            ans[p]=(char)(tmp%10+'0');
            prenos=tmp/10;
            p--;
        }
        if(prenos!=0)ans[p]=(char)(prenos+'0');
        pp--;
    }
    int ind=0;
    while(ans[ind]=='0')ind++;
    ans=ans.substr(ind, ans.size()-ind);
    return ans;
}
int main()
{
    string x;
    int n;
    cin>>x>>n;
    string lastnum="1", num="0";
    int brDig=0;
    while(brDig<n)
    {
        if(num=="0")num="1";
        else
        {
            num=multiLongNum(lastnum, x);
        }
        lastnum=num;
        brDig+=num.size();
    }
    n=brDig-n;
    cout<<num[num.size()-1-n]<<endl;
    return 0;
}
