/**
Ivo Karagyozov
Esenen 2013 D1 zero
*/
#include<iostream>
using namespace std;
bool str[10005];
int main()
{
    string s;
    cin>>s;
    int br=0, brZero=0;
    for(int i=0; i<s.size(); )
    {
        brZero=0;
        while(s[i]=='1')
        {
            i++;
            if(i==s.size())break;
        }
        if(i==s.size())break;
        while(s[i]=='0')
        {
            brZero++;
            i++;
            if(i==s.size())break;
        }
        if(brZero!=0 && str[brZero]==false)
        {
            br++;
            str[brZero]=true;
        }
    }
    cout<<br<<endl;
    return 0;
}
