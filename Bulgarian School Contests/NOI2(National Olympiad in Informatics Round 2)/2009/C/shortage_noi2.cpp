/**
Ivo Karagyozov
NOI2 2009 C2 shortage
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

string s, t, p;

int main()
{
    cin>>s;
    t=s;
    reverse(t.begin(), t.end());
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==s[s.size()-1])
        {
            if(s.substr(i, (s.size()-i)/2)==t.substr(0, (t.size()-i)/2))
            {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    return 0;
}
