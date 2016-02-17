/**
Ivo Karagyozov
Esenen 2009 D3 garden
*/
#include<iostream>
using namespace std;
bool m[10000];
int main()
{
    int a, b, p;
    cin>>a>>b>>p;
    int per=2*(a+b);
    int meter=0;
    m[meter]=true;
    int br=1;
    while(true)
    {
        meter+=p;
        meter%=per;
        if(m[meter]==true)break;
        br++;
        m[meter]=true;
    }
    cout<<br<<" ";
    long long sum=0;
    for(int i=1; i<per; i++)
    {
        if(m[i]==true)
        {
            if(i<=per-i)sum+=2*i;
            else sum+=2*(per-i);
        }
    }
    cout<<sum<<endl;
}
