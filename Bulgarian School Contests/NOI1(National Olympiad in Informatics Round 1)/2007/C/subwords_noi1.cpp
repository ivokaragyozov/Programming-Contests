/**
Ivo Karagyozov
NOI1 2007 C1 subwords
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string previous[100000];
int ind=0;
int cmp(string s, string t)
{
    if(s.size()<t.size())return 0;
    else if(s.size()>t.size())return 1;
    else
    {
        if(s<t)return 0;
        else if(s>t)return 1;
        else return 2;
    }
}
int cmp1(string s, string t)
{
    if(s.size()!=t.size())return s.size()<t.size();
    else return s<t;
}
bool BSearch(string target, int n)
{
    int le=0, ri=n-1;
    while(le<=ri)
    {
        int mid=(le+ri)/2;
        if(cmp(target, previous[mid])==0)
        {
            ri=mid-1;
        }
        else if(cmp(target, previous[mid])==1)
        {
            le=mid+1;
        }
        else return true;
    }
    return false;
}
int main()
{
    string word;
    cin>>word;
    for(int i=0; i<word.size(); i++)
    {
        string s="";
        for(int j=i; j<word.size(); j++)
        {
            s=s+word[j];
            if(BSearch(s, ind)==false)
            {
                previous[ind]=s;
                ind++;
                sort(previous, previous+ind, cmp1);
            }
        }
    }
    printf("%d\n", ind);
    return 0;
}
