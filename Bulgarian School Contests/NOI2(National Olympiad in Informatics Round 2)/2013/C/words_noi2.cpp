/**
Ivo Karagyozov
NOI2 2013 C3 words
*/
#include<iostream>
#include<cstdio>
using namespace std;
int dyn[20005];
int main()
{
    string s;
    cin>>s;
    int k;
    scanf("%d", &k);
    dyn[1]=1;
    for(int i=2; i<=s.size(); i++)
    {
        if(s[i-1]<s[i-2])
        {
            dyn[i]=dyn[i-1]+1;
        }
        else dyn[i]=dyn[i-1];
    }
    for(int i=0; i<k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        cout<<dyn[b]-dyn[a]+1<<endl;
    }
    return 0;
}
