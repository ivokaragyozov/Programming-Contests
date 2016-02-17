/**
Ivo Karagyozov
NOI1 2013 C3 barcode
*/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ind=3, br1=0, br2=0, br3=0;
    while(ind<s.size())
    {
        int num;
        num=1000*(s[ind++]-'0')+100*(s[ind++]-'0')+10*(s[ind++]-'0')+(s[ind]-'0');
        if(num%2==0)br1++;
        else if(num%3==0)br2++;
        else br3++;
        ind+=5;
    }
    printf("%d %d %d\n", br1, br2, br3);
    return 0;
}
