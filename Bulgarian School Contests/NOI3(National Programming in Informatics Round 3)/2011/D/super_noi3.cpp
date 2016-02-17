/**
Ivo Karagyozov
NOI3 2011 D6 super
*/
#include<iostream>
using namespace std;
const int N=10000005;
bool pr[N];
int main()
{
    pr[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        while(pr[i]==1 && i*i<=N)i++;
        for(int j=2*i;j<=N;j+=i)
        {
            pr[j]=1;
        }
    }
    int a,b;
    cin>>a>>b;
    if(a==1)a++;
    bool f=false;
    for(int i=a;i<=b;i++)
    {
        int p=i;
        bool k=false;
        while(p>0)
        {
            if(pr[p]==1)
            {
                k=true;
                break;
            }
            p=p/10;
        }
        if(k==false)
        {
            cout<<i<<endl;
            f=true;
        }
    }
    if(f==false)cout<<"NO"<<endl;
    return 0;
}
