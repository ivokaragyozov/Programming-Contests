/**
Ivo Karagyozov
Esenen 2011 D1 symmetric
*/
#include<iostream>
#include<algorithm>
using namespace std;
bool isSymmetric(string s)
{
    int i=0, j=s.size()-1;
    for(int i=0; i<s.size(); i++, j--)
    {
        if(s[i]!=s[j])return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    string s, tmp="", st;
    cin>>s;
    st=s;
    for(int i=0; i<s.size(); i++)
    {
        if(isSymmetric(st)==true)break;
        tmp=s.substr(0, i);
        reverse(tmp.begin(), tmp.end());
        st=s+tmp;
    }
    cout<<tmp.size()<<endl;
    if(tmp.size()!=0)
    {
        cout<<tmp<<endl;
    }
}
