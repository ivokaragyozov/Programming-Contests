#include <iostream>
#include <cmath>
#include <set>
#define endl '\n'
using namespace std;

const int sqrtMaxNumber = 1000005;

bool tPrimes[1000005];
int n;
long long a;
set <long long> results;

void generateTPrimes()
{
    int sqr = sqrt(sqrtMaxNumber);
    for(int i = 2; i <= sqr; i++)
    {
        if(!tPrimes[i])
        {
            for(int j = i*i; j < sqrtMaxNumber; j += i)
            {
                tPrimes[j] = 1;
            }
        }
    }

    for(int i = 2; i < sqrtMaxNumber; i++)
    {
        if(!tPrimes[i]) results.insert((long long)i*i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    generateTPrimes();

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        if(results.find(a) != results.end()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
