#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

struct tree
{
	long long x, h;

	tree(){}

	tree(long long x, long long h)
	{
		this->x = x;
		this->h = h;
	}
};

int n, treeInd, answer = 2;
long long x, h;
tree trees[maxN + 1];

bool cmp(tree a, tree b)
{
	return a.x < b.x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(int i = 0; i < n; i++)
	{
		cin>>x>>h;

		trees[treeInd++] = tree(x, h);
	}

	if(n == 1)
	{
		cout<<1<<endl;
		return 0;
	}

	sort(trees, trees + n, cmp);
	
	int leftX, rightX;
	for(int i = 1; i < n - 1; i++)
	{
		leftX = trees[i].x - trees[i].h;
		rightX = trees[i].x + trees[i].h;

		if(leftX > trees[i - 1].x) answer++;
		else if(rightX < trees[i + 1].x)
		{
			trees[i].x = rightX;
			answer++;
		}
	}

	cout<<answer<<endl;
	return 0;
}
