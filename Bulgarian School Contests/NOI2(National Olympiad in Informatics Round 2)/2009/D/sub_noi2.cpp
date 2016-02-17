/**
Ivo Karagyozov
NOI2 2009 D3 sub
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    string t;
    for(int i=s.size()-1;i>=0;i--)
    {
        t=t+s[i];
    }
    bool p=false;
    string b;
    for(int i=s.size()-1;i>=0;i--)
    {
        int umalitel,umalqemo,razlika;
        umalqemo=t[i]-'0';
        umalitel=s[i]-'0';
        if(p==true)
        {
            umalqemo--;
        }
        if(umalqemo<0)
        {
            umalqemo=9;
            p=true;
        }
        razlika=umalqemo-umalitel;
        if(razlika<0)
        {
            razlika+=10;
            p=true;
        }
        else p=false;
        char a;
        a=(char)(razlika+'0');
        b=a+b;
    }
    cout<<b<<endl;
    return 0;
}
