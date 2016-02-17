#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long t, n, sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n;

        if(n % 2 == 0) sum = (n + 1) * (n / 2);
        else sum = (n + 1) * (n / 2) + n / 2 + 1;

        for(int power = 1; power <= n; power *= 2)
        {
            sum -= 2 * power;
        }

        cout<<sum<<endl;
    }

    return 0;
}
