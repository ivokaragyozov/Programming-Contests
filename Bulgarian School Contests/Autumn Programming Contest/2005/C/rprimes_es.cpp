/**
Ivo Karagyozov
Esenen 2005 C1 rprimes
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long a, b;

bool isPrime(long long p)
{
    if(p < 2) return false;
    if(p == 2) return true;
    if(p % 2 == 0) return false;

    int sqr = sqrt(p);
    for(int i = 3; i <= sqr; i += 2)
    {
        if(p % i == 0) return false;
    }

    return true;
}
long long solve(int number)
{
    if(number > b) return 0;

    long long nums[10];
    for(int i = 1; i <= 9; i++)
    {
        nums[i - 1] = 10 * number + i;
    }

    long long ans = 0;
    for(int i = 0; i < 9; i++)
    {
        if(isPrime(nums[i])) ans += solve(nums[i]);
    }

    if(number >= a && number <= b) ans++;


    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b;

    cout<<solve(2) + solve(3) + solve(5) + solve(7)<<endl;
    return 0;
}
