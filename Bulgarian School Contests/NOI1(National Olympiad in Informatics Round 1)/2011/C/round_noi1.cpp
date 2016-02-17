#include<iostream>
#include<cstdio>
using namespace std;
string sumLongNums(string s, string t)
{
    if(s.size()<t.size())swap(s, t);
    string p;
    p.resize(s.size()-t.size(), '0');
    t=p+t;
    string rez="";
    int prenos=0;
    for(int i=s.size()-1; i>=0; i--)
    {
        int num=(s[i]-'0')+(t[i]-'0')+prenos;
        prenos=num/10;
        rez=(char)(num%10+'0')+rez;
    }
    if(prenos==1)rez='1'+rez;
    return rez;
}
bool isRound(string num)
{
    for(int i=0; i<num.size(); i++)
    {
        if(num[i]!='0' && num[i]!='6')return false;
    }
    return true;
}
int main()
{
    int k;
    scanf("%d", &k);
    string num="0";
    long long br=0;
    while(1)
    {
        if(isRound(num)==true)br++;
        if(br==k)break;
        num=sumLongNums(num, "6");
    }
    cout<<num<<endl;
    return 0;
}
