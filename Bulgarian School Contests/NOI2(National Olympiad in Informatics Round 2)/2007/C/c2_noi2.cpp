/**
Ivo Karagyozov
NOI2 2007 C2 c2
*/
#include<iostream>
#include<cstdio>
using namespace std;

string num;
int digs[105], maxdig=0;

int main()
{
    cin>>num;
    for(int i=0; i<num.size(); i++)
    {
        digs[i]=num[i]-'0';
        if(digs[i]>maxdig)maxdig=digs[i];
    }
    printf("%d\n", maxdig);
    for(int i=0; i<maxdig; i++)
    {
        string t="";
        for(int j=0; j<num.size(); j++)
        {
            if(digs[j]!=0)
            {
                t+='1';
                digs[j]--;
            }
            else
            {
                t+='0';
            }
        }
        for(int j=0; j<t.size(); j++)
        {
            if(t[j]=='1')break;
            else
            {
                t[j]=' ';
            }
        }
        cout<<t<<endl;
    }
}
