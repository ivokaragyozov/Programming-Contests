/**
Ivo Karagyozov
NOI2 2014 D3 egypt
*/
#include<iostream>
using namespace std;
int main()
{
    int z;
    cin>>z;
    int x=z,y=z+1;
    while(x<y)
    {
        x++;
        y=(z*x)/(x-z);
        if(x<y && x*y==z*x+z*y)cout<<x<<" "<<y<<endl;
    }
    return 0;
}
