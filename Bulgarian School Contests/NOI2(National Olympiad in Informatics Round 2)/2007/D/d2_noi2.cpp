/**
Ivo Karagyozov
NOI2 2007 D2 d2
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long tri=1,piram=1,step=2;
    long long x=2;
    for(int i=1;i<n-1;i++)
    {
        tri=tri+x;
        x++;
    }
    cout<<tri<<" ";
    x=1;
    long long y=2;
    for(int i=1;i<n-2;i++)
    {
        piram=piram+x+y;
        x=x+y;
        y++;
    }
    cout<<piram<<" ";
    for(int i=1;i<n;i++)
    {
        step=step*2;
    }
    cout<<step<<endl;
    return 0;
}
