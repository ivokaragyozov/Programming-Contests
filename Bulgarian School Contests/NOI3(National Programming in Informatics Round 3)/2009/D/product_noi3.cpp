/**
Ivo Karagyozov
NOI3 2009 D3 product
*/
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char a[55];
    string s;
    getline(cin,s,'\n');
    for(int i=0;i<n;i++)
    {
        cin.get(a[i]);
        getline(cin,s,'\n');
    }
    int minm=1<<30;
    for(int i=0;i<=n-m;i++)
    {
        int multi=1;
        for(int j=0;j<m;j++)
        {
            multi*=(int)(a[i+j]-'0');
        }
        if(multi<minm)minm=multi;
    }
    cout<<minm<<endl;
    return 0;
}
