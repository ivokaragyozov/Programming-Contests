#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

const int maxN = 50;

int n, a1[maxN + 5], a2[maxN + 5], b[maxN + 5], minTime = INT_MAX, secondMinTime = INT_MAX;

void solve(int row, int house, int time)
{
    if(row == 1 && house == 1)
    {
        if(time < minTime)
        {
            secondMinTime = minTime;
            minTime = time;
        }
        else if(time < secondMinTime) secondMinTime = time;

        return;
    }

    if(row == 2)
    {
        if(house != 1) solve(row, house - 1, time + a2[house - 1]);
        solve(row - 1, house, time + b[house]);
    }
    else solve(row, house - 1, time + a1[house - 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n - 1; i++)
    {
        cin>>a1[i];
    }
    for(int i = 1; i <= n - 1; i++)
    {
        cin>>a2[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin>>b[i];
    }

    solve(2, n, 0);

    cout<<minTime + secondMinTime<<endl;
    return 0;
}
