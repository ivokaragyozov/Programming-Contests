/**
Ivo Karagyozov
NOI2 2006 C2 bmax
*/
#include<iostream>
#include<cstdio>
using namespace std;

int x, y=x;

int fromBinToDec(string s)
{
    int t=s[0]-'0';
    for(int i=1; i<s.size(); i++)
    {
        t=t*2+(s[i]-'0');
    }
    return t;
}
string fromDecToBin(int n)
{
    int k=1<<30;
    string t;
    for(int i=0; i<31; i++)
    {
        if((k&n)>0)t=t+'1';
        else t=t+'0';
        k=k>>1;
    }
    int j=0;
    while(t[j]=='0')j++;
    t=t.substr(j);
    return t;
}

int main()
{
    scanf("%d", &x);
    string s=fromDecToBin(x);
    for(int i=0; i<s.size(); i++)
    {
        s=s[s.size()-1]+s;
        s.erase(s.size()-1, 1);
        if(fromBinToDec(s)>y)
        {
            y=fromBinToDec(s);
        }
    }
    printf("%d\n", y);
    return 0;
}
