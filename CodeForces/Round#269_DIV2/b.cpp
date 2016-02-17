#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

struct task
{
	int diff, number;
};

int n, diff, seqInd = 2;
task seq1[2005], seq2[2005], seq3[2005];

bool cmp(task a, task b)
{
	return a.diff < b.diff;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>diff;

		seq1[i].diff = diff;
		seq1[i].number = i + 1;
	}

	sort(seq1, seq1 + n, cmp);

	for(int i = 0; i < n; i++)
	{
		seq2[i] = seq1[i];
		seq3[i] = seq1[i];
	}

	for(int i = 1; i < n; i++)
	{
		if(seq1[i].diff == seq1[i-1].diff)
		{
			if(seqInd == 2)
			{
				swap(seq2[i], seq2[i-1]);
				seqInd++;
			}
			else
			{
				swap(seq3[i], seq3[i-1]);
				seqInd++;
				break;
			}
		}
	}

	if(seqInd != 4) cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(int i = 0; i < n; i++) cout<<seq1[i].number<<" ";
		cout<<endl;
		for(int i = 0; i < n; i++) cout<<seq2[i].number<<" ";
		cout<<endl;
		for(int i = 0; i < n; i++) cout<<seq3[i].number<<" ";
		cout<<endl;
	}
}
