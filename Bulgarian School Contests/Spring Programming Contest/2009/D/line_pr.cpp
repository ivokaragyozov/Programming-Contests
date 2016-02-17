/**
Ivo Karagyozov
Proleten 2009 D2 line
*/
#include<iostream>
using namespace std;
const int N=50005;
int a[N];
int main()
{
    int n;
    cin>>n;
    int p1,p2;
    p1=0;
    p2=1;
    int i,j;
    for(i=1,j=1;j<N;i+=p1,j+=p2)
    {
        a[i]=1;
        a[j]=2;
        p1++;
        p2++;
    }
    int b;
    cin>>b;
    bool k;
    if(a[b]==1)k=false;
    else k=true;
    for(i=1;i<n;i++)
    {
        cin>>b;
        if(a[b]==1 || b==1)
        {
            if(k!=false)
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        else if(a[b]==0)
        {
            cout<<"No"<<endl;
            return 0;
        }
        else if(b!=1)
        {
            if(k!=true)
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    if(k==false)cout<<1;
    else cout<<2;
    cout<<endl;
    return 0;
}
