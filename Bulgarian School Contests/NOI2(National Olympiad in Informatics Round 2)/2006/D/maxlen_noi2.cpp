/**
Ivo Karagyozov
NOI2 2006 D3 maxlen
*/
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a;
    b=a;
    int br=1,maxlen=0;
    while(a!=0)
    {
        cin>>a;
        if(a==b)br++;
        else if(br>maxlen)
        {
            maxlen=br;
            br=1;
        }
        b=a;
    }
    cout<<maxlen<<endl;
    return 0;
}
