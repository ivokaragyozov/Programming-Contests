#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct xorshift
{
	unsigned x,y,z,w;
	xorshift(): x(123456789), y(92737287), z(7777777), w(823783287) {}
	unsigned next() {
		unsigned t=x^(x<<11);
		x=y;y=z;z=w;
		return w=w^(w>>19)^t^(t>>8);
	}
};

unsigned long long n, t;
xorshift ran;

unsigned long long quickPow(unsigned long long a, unsigned long long b, unsigned long long mod)
{
    if(b == 0) return 1;
    if(b % 2 == 0)
    {
        unsigned long long curr = quickPow(a, b / 2, mod);
        return (curr * curr) % mod;
    }
    else
    {
        return (quickPow(a, b - 1, mod) * a) % mod;
    }
}
bool ferma(unsigned long long a)
{
    for(int i = 0; i <= 32; i++)
    {
        unsigned long long curr = ran.next() % (a - 1) + 1;

        if(quickPow(curr, a - 1, a) != 1) return false;
    }

    return true;
}
unsigned long long calculate(unsigned long long a)
{
    for(unsigned long long i = a - 1; i >= 2; i--)
    {
        if(ferma(i)) return i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n;

        cout<<calculate(n)<<endl;
    }

    return 0;
}
