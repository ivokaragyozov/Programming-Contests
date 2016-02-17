#include <iostream>
#include <algorithm>
#include <climits>
#define endl '\n'
using namespace std;

struct town
{
    int townNumber, cordinates;
};

int n, answer[100005][2];
town towns[100005];

bool cmp(town a, town b)
{
    return a.cordinates<b.cordinates;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>towns[i].cordinates;
        towns[i].townNumber = i;
    }

    sort(towns, towns+n, cmp);
    int nearestRight = INT_MAX, nearestLeft = INT_MAX, distantRight = -1, distantLeft = -1;
    for(int i = 0; i < n; i++)
    {
        if(i != 0)
        {
            nearestLeft = abs(towns[i-1].cordinates-towns[i].cordinates);
            distantLeft = abs(towns[0].cordinates-towns[i].cordinates);
        }
        if(i != n-1)
        {
            nearestRight = abs(towns[i+1].cordinates-towns[i].cordinates);
            distantRight = abs(towns[n-1].cordinates-towns[i].cordinates);
        }

        answer[towns[i].townNumber][0] = min(nearestLeft, nearestRight);
        answer[towns[i].townNumber][1] = max(distantLeft, distantRight);
    }

    for(int i = 0; i < n; i++)
    {
        cout<<answer[i][0]<<" "<<answer[i][1]<<endl;
    }
    return 0;
}
