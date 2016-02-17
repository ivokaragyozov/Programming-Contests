/**
Ivo Karagyozov
Proleten 2012 D2 processor
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1005],b[1005],sumofb=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        sumofb+=b[i];
    }
    int maxbeza=b[n-1],maxbezb=a[0],beza=b[n-1],bezb=a[0];
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]<b[i])
        {
            if(b[i]-a[i+1]>maxbeza)maxbeza=b[i]-a[i+1];
            beza+=b[i]-a[i+1];
        }
        else
        {

            if(a[i+1]-b[i]>maxbezb)maxbezb=a[i+1]-b[i];
            bezb+=a[i+1]-b[i];
        }
    }
    cout<<sumofb+bezb<<" "<<maxbeza<<" "<<maxbezb<<endl;
    return 0;
}
