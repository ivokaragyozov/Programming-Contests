/**
Ivo Karagyozov
NOI2 2008 C3 justify
*/
#include<iostream>
#include<cstdio>
using namespace std;

int n;
string s;

int main()
{
    scanf("%d", &n);
    getline(cin, s, '\n');
    for(int i=0; i<n; i++)
    {
        string t="";
        getline(cin, s, '\n');
        int k=1;
        while(s[0]==' ')s=s.substr(k++);
        t=s[0];
        for(int j=1; j<s.size(); j++)
        {
            if(!(s[j]==' ' && s[j-1]==' '))t+=s[j];
        }
        s=t;
        int brwords=0;
        for(int j=0; j<s.size(); j++)
        {
            if(s[j]==' ')brwords++;
        }
        brwords++;
        t="";
        if(i!=n-1)
        {
            int p=(60-s.size()+brwords)/(brwords-1), q=(60-s.size()+brwords)%(brwords-1);
            for(int j=0; j<s.size(); j++)
            {
                if(s[j]!=' ')t+=s[j];
                else
                {
                    for(int a=0; a<p; a++)
                    {
                        t+=' ';
                    }
                    if(q>0)
                    {
                        t+=' ';
                        q--;
                    }
                }
            }
        }
        else t=s;
        cout<<t<<endl;
    }
    return 0;
}
