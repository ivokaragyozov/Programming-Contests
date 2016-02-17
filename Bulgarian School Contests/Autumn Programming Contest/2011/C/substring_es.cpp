/**
Ivo Karagyozov
Esenen 2011 C2 substring
*/
#include<iostream>

using namespace std;

int main()
{
    long long sizeNiz=0;
    cin>>sizeNiz;
    long long pos1, pos2;
    cin>>pos1>>pos2;

    long long brbBefore=pos1-1, brbBetween=pos2-pos1-1, brbAfter=sizeNiz-pos2;
    long long ans=brbBefore+brbBetween+brbBefore*brbBetween+brbBetween+brbAfter+brbBetween*brbAfter+brbBefore+brbAfter+brbBefore*brbAfter+3;
    long long num=123456789;

    cout<<ans%num<<endl;

    return 0;
}
