/**
Ivo Karagyozov
NOI1 2014 D1 cinema
*/
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int pos;
    cin>>pos;
    int r,k;
    if(pos%m==0)r=pos/m;
    else r=pos/m+1;
    if(pos%m==0)k=m;
    else k=pos%m;
    cout<<r<<" "<<k<<endl;
    return 0;
}
