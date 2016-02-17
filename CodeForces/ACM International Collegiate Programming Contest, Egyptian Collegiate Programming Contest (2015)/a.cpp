#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 15;

char ch;
int t, a[maxN], a1[maxN], ind, fact[15] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
double ans;

int codePermutation(int n, int *perm)
{
	int *p = new int[n+1], res = 0, tmp;
	for(int i = 1; i <= n; i++)
		p[i-1] = i;

	for(int pos = 0; pos < n; pos++)
	{
		tmp = 0;
		while(perm[pos] != p[tmp])
			tmp++;
		res = res * (n-pos) + tmp;
		for(int i = tmp + 1; i < n; i++)
			p[i-1] = p[i];
	}

	return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        ind = 0;
        ans = 0;
        if(cs == 0)cin.get(ch);
        while(1)
        {
            cin.get(ch);
            if(ch == endl) break;

            a[ind] = (ch - '0');
            a1[ind++] = (ch - '0');
        }
        sort(a1, a1 + ind);

        for(int i = 0; i < ind; i++)
        {
            for(int j = 0; j < ind; j++)
            {
                if(a[i] == a1[j])
                {
                    a[i] = j + 1;
                    break;
                }
            }
        }


        int b = fact[ind] - codePermutation(ind, a) - 1;
        double curr = 1.0 / fact[ind];
        for(int i = 0; i < b; i++)
        {
            ans += curr;
            curr *= curr;
        }

        cout<<fixed<<setprecision(9);
        cout<<ans<<endl;
    }

    return 0;
}
