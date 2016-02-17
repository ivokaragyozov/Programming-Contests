/**
Ivo Karagyozov
NOI2 2010 D3 tetris
*/
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    string s;
    int brp=0,total=0;
    for(int i=0;i<a;i++)
    {
        cin>>s;
        bool p=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='*')
            {
                p=true;
            }
        }
        if(p!=true)brp++;
        else
        {
            total=total+(brp*(brp+1))/2;
            brp=0;
        }
    }
    total=total+(brp*(brp+1))/2;
    cout<<total<<endl;
    return 0;
}
