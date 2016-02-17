/**
Ivo Karagyozov
NOI2 2012 D1 limes
*/
#include<iostream>
using namespace std;
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    if(x%2!=0)
    {
        cout<<(x-1)*m+y-1<<endl;
    }
    else
    {
        cout<<x*m-y<<endl;
    }
    return 0;
}
