/**
Ivo Karagyozov
NOI2 2007 D1 d1
*/
#include<iostream>
using namespace std;
int toup(string s)
{
    int sum=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=toupper(s[i]))
        {
            sum=sum+(26-(s[i]-'a'));
        }
    }
    return sum;
}
int todown(string s)
{
    int sum=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=tolower(s[i]))
        {
            sum=sum+(1+(s[i]-'A'));
        }
    }
    return sum;
}
int main()
{
    string s;
    getline(cin,s);
    s=s+'\n';
    int sum=0;
    for(int i=0;i<s.size();i++)
    {
        string t;
        while(isalpha(s[i]))
        {
            t=t+s[i];
            i++;
        }
        sum=sum+min(toup(t),todown(t));
    }
    cout<<sum<<endl;
    return 0;
}
