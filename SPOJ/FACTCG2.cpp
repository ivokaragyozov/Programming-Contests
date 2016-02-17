#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e7 + 5;

int sieve[maxN], n;

void generateSieve()
{
    sieve[1] = 2;
    for(long long i = 2; i <= maxN; i++)
    {
        if(sieve[i]) continue;

        sieve[i] = i;
        for(long long j = 2 * i; j <= maxN; j += i)
        {
            if(sieve[j] == 0) sieve[j] = i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    generateSieve();

    while(cin>>n)
    {
        cout<<1;
        while(n % sieve[n] == 0)
        {
            cout<<" x "<<sieve[n];
            n /= sieve[n];
        }
        cout<<endl;
    }

    return 0;
}
