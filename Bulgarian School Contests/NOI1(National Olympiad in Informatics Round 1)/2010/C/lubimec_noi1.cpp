/**
Ivo Karagyozov
NOI1 2010 C3 lubimec
*/
#include<iostream>
#include<cstdio>
using namespace std;
bool isLubimo(string s)
{
    bool p=false;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='1')p=true;
        if(s[i]=='3' && p==true)return true;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d", &n);
    int br=0;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        if(isLubimo(s)==true)br++;
    }
    if(br!=0)printf("%d\n", br);
    else printf("No\n");
    return 0;
}
