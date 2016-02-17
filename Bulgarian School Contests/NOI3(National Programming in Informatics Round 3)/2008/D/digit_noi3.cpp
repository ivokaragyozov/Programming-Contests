/**
Ivo Karagyozov
NOI3 2008 D3 digit
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int brd=0;
    for(int i=1;;i++)
    {
        int p=i;
        while(p>0)
        {
            int r=p%10;
            p=p/10;
            brd++;
            if(brd==n)
            {
                cout<<r<<endl;
                return 0;
            }
        }
    }
}
