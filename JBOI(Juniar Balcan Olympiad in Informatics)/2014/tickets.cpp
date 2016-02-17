/**
Ivo Karagyozov
JBOI 2014 2.2 tickets
*/
#include <iostream>
#define endl '\n'
using namespace std;

long long n, k, power = 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        power *= 2;
    }
    while(power > 1)
    {
        if(k > power/2)
        {
            cout<<1;
            k = power/2-(k-power/2)+1;
        }
        else
        {
            cout<<0;
        }
        power /= 2;
    }
    return 0;
}

