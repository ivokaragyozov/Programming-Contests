/**
Ivo Karagyozov
NOI2 2014 E1 rest
*/
#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int n,m;
    n=a*100+b;
    m=c*100+d;
    if(m>n)swap(n,m);
    int x,k;
    cin>>x>>k;
    n=n-100;
    int sizet=0,brs=0,brm=0;
    while(1)
    {
        sizet+=k*x;
        brs+=k;
        bool p=false;
        while(sizet>n)
        {
            sizet=sizet-x;
            brs--;
            p=true;
        }
        if(p==false && sizet!=n)sizet+=50;
        if(p==true || sizet==n)break;
    }
    brm=brs/k;
    if(brs%k!=0)brm++;
    cout<<brs*2<<endl<<brm<<endl;
    return 0;
}
