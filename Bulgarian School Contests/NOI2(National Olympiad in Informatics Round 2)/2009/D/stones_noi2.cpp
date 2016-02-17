/**
Ivo Karagyozov
NOI2 2009 D1 stones
*/
#include<iostream>
using namespace std;
bool p[10005];
int main()
{
    int n;
    cin>>n;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        p[a]=true;
    }
    int br=0;
    for(int i=0;i<=10000;i++)
    {
        if(p[i]==true)
        {
            br++;
        }
    }
    cout<<br<<endl;
    return 0;
}
