#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

long long n, ans = 1;

void dels(long long a)
{
    long long sqr = sqrt(a), a1 = a;
    for(long long i = 2; i <= sqr; i++)
    {
        if(a == 1) break;

        if(a % i == 0)
        {
            ans *= i;

            while(a % i == 0) a /= i;
        }
    }

    if(a != 1) ans *= a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    dels(n);
    cout<<ans<<endl;
    return 0;
}
