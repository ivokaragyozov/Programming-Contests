/**
Ivo Karagyozov
NOI3 2009 D1 ones
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<i;
    }
    for(int i=n-1;i>=1;i--)
    {
        cout<<i;
    }
    cout<<endl;
    return 0;
}
