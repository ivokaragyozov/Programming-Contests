#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 3e5 + 5;

struct segment
{
	int le, ri;
};

int n, a[maxN], indSeg, firstNotUsed;
segment segments[maxN];
map<int, int> used;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	for(int i = 0; i < n; i++)
	{
		if(used.find(a[i]) != used.end() && used[a[i]] != -1 && used[a[i]] >= firstNotUsed)
		{
			used[a[i]] = -1;
			segments[indSeg].le = firstNotUsed;
			segments[indSeg++].ri = i;
			firstNotUsed = i + 1;
		}
		else used[a[i]] = i;
	}

	if(firstNotUsed != n) segments[indSeg - 1].ri = n - 1;

	if(indSeg == 0) cout<<-1<<endl;
	else
	{
		cout<<indSeg<<endl;
		for(int i = 0; i < indSeg; i++)
		{
			cout<<segments[i].le + 1<<" "<<segments[i].ri + 1<<endl;
		}
	}

	return 0;
}
