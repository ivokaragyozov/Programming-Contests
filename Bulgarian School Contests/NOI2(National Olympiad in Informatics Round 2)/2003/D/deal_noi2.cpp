/**
Ivo Karagyozov
NOI2 2003 D1 deal
*/
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int k;
    cin>>k;
    int c=(a*k)/b;
    if(c*b<a*k)c++;
    cout<<c-k+1<<endl;
    return 0;
}
