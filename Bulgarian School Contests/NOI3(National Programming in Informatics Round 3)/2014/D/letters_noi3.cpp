/**
Ivo Karagyozov
NOI3 2014 D4 letters
*/
#include<iostream>
using namespace std;
const int N=100005;
int p[N];
bool k[N];
int main()
{
    int n,m;
    cin>>n>>m;
    int br=0;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a!=b)
        {
            if(p[a]==0 && p[a]!=b)p[a]=b;
            else if(k[a]==false && p[a]!=b)
            {
                k[a]=true;
                br++;
            }
            if(p[b]==0 && p[b]!=a)p[b]=a;
            else if(k[b]==false && p[b]!=a)
            {
                k[b]=true;
                br++;
            }
        }
    }
    cout<<n-br<<endl;
    return 0;
}

