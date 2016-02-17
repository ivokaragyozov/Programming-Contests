#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 100005;

struct point
{
	char type;
	int x;

	point(){}
	point(int x, char type)
	{
		this->x = x;
		this->type = type;
	}
};

int n, a, b, ind_point, curr_cnt, max_cnt, cnt_ans, ans, last_i;
point points[2 * maxN];

bool cmp(point x, point y)
{
	if(x.x != y.x) return x.x < y.x;
	else return x.type < y.type;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b;
		points[ind_point++] = point(a, 'b');
		points[ind_point++] = point(b, 'e');
	}

	sort(points, points + ind_point, cmp);

	for(int i = 0; i < ind_point; i++)
	{
		if(points[i].type == 'e') curr_cnt--;
		
		cout<<curr_cnt<<endl;

		if(curr_cnt > max_cnt)
		{
			max_cnt = curr_cnt;
			ans = 1;
		}
		else if(curr_cnt == max_cnt)
		{
			ans++;
		}

		if(points[i].type == 'b') curr_cnt++;
	}


	if(curr_cnt == max_cnt) ans++;
	cout<<ans<<endl;
	return 0;
}
