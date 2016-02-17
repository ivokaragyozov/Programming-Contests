#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 2000;

struct student
{
	int rating, number;
};

int n, currPos = 1, currCnt, rating, results[maxN + 2];
student students[maxN + 2];

bool cmp(student a, student b)
{
	return a.rating > b.rating;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>rating;

		students[i].rating = rating;
		students[i].number = i + 1;
	}

	sort(students, students + n, cmp);

	for(int i = 0; i < n; i++)
	{
		if(i == 0 || students[i - 1].rating == students[i].rating)
		{
			currCnt++;
			results[students[i].number] = currPos;
		}
		else
		{
			currPos += currCnt;
			currCnt = 1;

			results[students[i].number] = currPos;
		}
	}

	for(int i = 1; i <= n; i++)
	{
		cout<<results[i];

		if(i == n) cout<<endl;
		else cout<<" ";
	}
	return 0;
}
