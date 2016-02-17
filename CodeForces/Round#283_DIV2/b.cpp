#include<iostream>
#include<cstdio>
using namespace std;
string button1(string s)
{
    for(int i=0; i<s.size(); i++)
    {
        int n=s[i]-'0';
        n++;
        n=n%10;
        s[i]=(char)(n+'0');
    }
    return s;
}
string button2(string s)
{
    char a=s[0];
    for(int i=1; i<s.size(); i++)
    {
        char b=s[i];
        s[i]=a;
        a=b;
    }
    s[0]=a;
    return s;
}
int main()
{
    int n;
    scanf("%d", &n);
    string s, t;
    cin>>s;
    t.resize(s.size(), '9');
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<s.size(); j++)
        {
            s=button2(s);
            if(s<t)t=s;
        }
        s=button1(s);
    }
    printf("%s\n", t.c_str());
    return 0;
}
