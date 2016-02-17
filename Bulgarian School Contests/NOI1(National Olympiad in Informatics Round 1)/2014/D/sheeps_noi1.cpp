/**
Ivo Karagyozov
NOI1 2014 D3 sheeps
*/
#include<iostream>
using namespace std;
int main()
{
    int k;
    cin>>k;
    long long bragneta=2,na1god=1,na2god=0,novorod=1,brraj=1;
    for(int i=0;i<k;i++)
    {
        bragneta=bragneta+novorod;
        brraj+=na2god;
        na2god=na1god;
        na1god=novorod;
        novorod=brraj;
    }
    cout<<bragneta<<endl;
    return 0;
}
