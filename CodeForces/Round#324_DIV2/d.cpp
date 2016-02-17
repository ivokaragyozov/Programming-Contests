#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int n, primes[3], indOfPrime = 0;

bool isPrime(int a)
{
	if(a < 2) return false;
	if(a == 2) return true;
	if(a % 2 == 0) return false;

	int sqr = sqrt(a);
	for(int i = 3; i <= sqr; i += 2)
	{
		if(a % i == 0) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	if(isPrime(n))
	{
		cout<<1<<endl<<n<<endl;
		return 0;
	}
	
	if(n % 2 != 0)
	{
		for(int i = n; i >= 0; i--)
		{
			if(isPrime(i))
			{
				n -= i;
				primes[indOfPrime++] = i;
				break;
			}
		}
	}


	if(n == 2)
	{
		cout<<2<<endl<<2<<" "<<primes[0]<<endl;
		return 0;
	}
	int sqr = sqrt(n);
	for(int i = 2; i <= n; i++)
	{
		if(isPrime(i) && isPrime(n - i))
		{
			primes[indOfPrime++] = i;
			primes[indOfPrime++] = n - i;
			break;
		}
	}

	cout<<indOfPrime<<endl;
	for(int i = 0; i < indOfPrime; i++)
	{
		if(i != indOfPrime - 1) cout<<primes[i]<<" ";
		else cout<<primes[i]<<endl;
	}

	return 0;
}
