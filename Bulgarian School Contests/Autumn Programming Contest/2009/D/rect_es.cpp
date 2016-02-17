/**
Ivo Karagyozov
Esenen 2009 D1 rect
*/
#include<iostream>
#include<climits>
using namespace std;
int minp=INT_MAX, br=0;
void str(int s)
{
    for(int i=1; i*i<=s; i++)
    {
        if(s%i==0)
        {
            int a=i, b=s/i;
            int p=2*a+2*b;
            if(p<minp)minp=p;
            br++;
        }
    }
}
int main()
{
    int s;
    cin>>s;
    str(s);
    cout<<br<<" "<<minp<<endl;
}
