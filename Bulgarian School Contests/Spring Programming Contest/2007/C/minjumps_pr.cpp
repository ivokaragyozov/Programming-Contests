/**
Ivo Karagyozov
Proleten 2007 C3 minjumps
*/
#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int a, b, n, x, y, minsum=1<<31-1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b>>n;
    for(int i=-10000; i<=10000; i++)
    {
        if((n-a*i)%b==0)
        {
            if(minsum>abs(i)+abs((n-a*i)/b))
            {
                minsum=abs(i)+abs((n-a*i)/b);
            }
        }
    }
    cout<<minsum<<endl;
    return 0;
}
