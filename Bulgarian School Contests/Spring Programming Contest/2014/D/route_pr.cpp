/**
Ivo Karagyozov
Proleten 2014 D1 route
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long maxs=-100005,m,beg=0,teksum=0,a,b;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        if(teksum<0)
        {
            beg=i;
            teksum=0;
        }
        teksum+=m;
        if(teksum>maxs)
        {
            maxs=teksum;
            a=beg;
            b=i;
        }
    }
    a++;
    b++;
    cout<<maxs<<" "<<a<<" "<<b<<endl;
    return 0;
}
