/**
Ivo Karagyozov
Esenen 2009 D2 maxbin
*/
#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int br1=0, br0=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='1')br1++;
        else br0++;
    }
    string ans="";
    for(int i=0; i<br1; i++)ans+='1';
    for(int i=0; i<br0; i++)ans+='0';
    cout<<ans<<endl;
    return 0;
}
