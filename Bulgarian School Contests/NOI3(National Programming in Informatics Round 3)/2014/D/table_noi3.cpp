/**
Ivo Karagyozov
NOI3 2014 D3 table
*/
#include<iostream>
using namespace std;
const int N=30005;
int p[N];
int main()
{
    int n=1,m=1;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)break;
        bool k=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>p[j];
                if(i!=0 && j!=m-1)
                {
                    if(p[j+1]!=p[j])
                    {
                        k=true;
                    }
                }
            }
        }
        if(k==false)cout<<"Y";
        else cout<<"N";
    }
    cout<<endl;
    return 0;
}
