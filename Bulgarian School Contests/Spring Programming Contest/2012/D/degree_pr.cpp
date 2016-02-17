/**
Ivo Karagyozov
Proleten 2012 D1 degree
*/
#include<iostream>
using namespace std;
const int N=1000000000;
int main()
{
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        long long p=0;
        bool q=false;
        for(int i=2;i*i<=x;i++)
        {
            p=i*i;
            bool k=false;
            while(p<N)
            {
                if(p==x)
                {
                    k=true;
                    break;
                }
                p=p*i;
            }
            if(k==true)
            {
                cout<<"YES"<<endl;
                q=true;
                break;
            }
        }
        if(q==false)cout<<"NO"<<endl;
    }
    return 0;
}
