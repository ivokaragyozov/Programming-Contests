#include<iostream>
#include<cstdio>
using namespace std;
long long fromBinToDec(string s)
{
    long long p=1, num=0;
    for(int i=s.size()-1; i>=0; i--)
    {
        num+=p*(s[i]-'0');
        p=p*2;
    }
    return num;
}
int main()
{
    cout<<fromBinToDec("111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
    string s;
    cin>>s;
    long long num=fromBinToDec(s);
    if(num%7==0)
    {
        printf("YES\n");
        return 0;
    }

    int ans=7-num%7;
    printf("%d\n", ans);
    return 0;
}
