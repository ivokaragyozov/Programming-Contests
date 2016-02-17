#include <iostream>
#include <algorithm>
#include <climits>
#define endl '\n'
using namespace std;

const int maxN = 100, maxC = 4;

struct card
{
	int number, color;

	card(){}
	card(int number, int color)
	{
		this->number = number;
		this->color = color;
	}
};

int c, n, a, b, colors[maxC + 5], arr[maxN * maxC + 5], sizeOfLis, answer = INT_MAX;
card cards[maxN * maxC + 5];

void generateArray()
{
	int numberOfColor, currColor;

	for(int i = 0; i < c * n; i++)
	{
		currColor = cards[i].color;

		for(int j = 0; j < c; j++)
		{
			if(colors[j] == currColor)
			{
				numberOfColor = j;
				break;
			}
		}
		arr[i] = numberOfColor * n + cards[i].number;
	}
}
int lis()
{
	int array[maxN * maxC + 5] = {0}, ind = 0, le, ri, mid, nearest;
	for(int i = 0; i < c * n; i++)
	{
		if(ind == 0 || arr[i] > array[ind - 1]) array[ind++] = arr[i];
		else
		{
			le = 0;
			ri = ind - 1;
			while(le <= ri)
			{
				mid = (le + ri) / 2;
				if(array[mid] > arr[i])
				{
					nearest = mid;
					ri = mid - 1;
				}
				else if(array[mid] < arr[i]) le = mid + 1;
				else
				{
					nearest = mid;
					break;
				}
			}

			array[nearest] = arr[i];
		}
	}
	return ind;
}

int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);*/

	cin>>c>>n;
	for(int i = 0; i < c * n; i++)
	{
		cin>>a>>b;
		cards[i] = card(b, a);
	}
	for(int i = 0; i < c; i++)
	{
		colors[i] = i + 1;
	}

	do
	{
		generateArray();

		sizeOfLis = lis();
		if(c * n - sizeOfLis < answer) answer = c * n - sizeOfLis;
	}
	while(next_permutation(colors, colors + c));

	cout<<answer<<endl;
	return 0;
}
