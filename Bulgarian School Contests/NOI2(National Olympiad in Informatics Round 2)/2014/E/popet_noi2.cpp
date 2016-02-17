/**
Ivo Karagyozov
NOI2 2014 E3 popet
*/
#include<iostream>
using namespace std;
int main()
{
    char c;
    int a=0;
    bool p=false;
    while(1)
    {
        cin>>c;
        if(c=='!')
        {
            cout<<a*5<<endl;
            break;
        }
        a=10*a+c-'0';
        if (p==true || (p==false && a>1))
        {
            cout<<a/2;
            p=true;
        }
        a=a%2;
    }
    return 0;
}
