/**
Ivo Karagyozov
NOI2 2012 D3 marbles
*/
#include<iostream>
using namespace std;
int main()
{
    string s,t;
    cin>>s;
    while(1)
    {
        t=s;
        int len=1,beg=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i-1]==s[i])
            {
                len++;
            }
            else
            {
                if(len>=3)
                {
                    beg=i-len;
                    s.erase(beg,len);
                }
                len=1;
            }
            if(s.size()-1==i)
            {
                i++;
                if(len>=3)
                {
                    beg=i-len;
                    s.erase(beg,len);
                }
            }
        }
        if(s==t)break;
    }
    if(s.size()==0)cout<<"EMPTY"<<endl;
    else cout<<s<<endl;
    return 0;
}
