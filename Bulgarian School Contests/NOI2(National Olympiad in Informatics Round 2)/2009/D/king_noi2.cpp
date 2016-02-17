/**
Ivo Karagyozov
NOI2 2009 D2 king
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    n=(n-1)/2;
    int a[1005],b[1005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    int minkm=1005;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                if(i+j<minkm)
                {
                    minkm=i+j;
                }
            }
        }
    }
    cout<<minkm<<endl;
    return 0;
}
