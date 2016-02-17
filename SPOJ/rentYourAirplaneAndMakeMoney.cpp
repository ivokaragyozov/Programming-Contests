#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

struct action
{
    int startTime, endTime, price;

    action()
    {
        startTime = 0;
        endTime = 0;
        price = 0;
    }
    action(int startTime, int endTime, int price)
    {
        this->startTime = startTime;
        this->endTime = endTime;
        this->price = price;
    }
};

int t, n, startTime, duration, price, endTime, sums[10005], maxPos[10005];
action dp[10005];

bool cmp(action a, action b)
{
    if(a.endTime != b.endTime) return a.endTime < b.endTime;
    else return a.startTime > b.startTime;
}
int binarySearch(int target)
{
    int le = 0, ri = n-1, mid, nearestLeft = -1;
    while(le <= ri)
    {
        mid = (le+ri)/2;

        //if(target == 5) cout<<"mid  "<<mid<<endl;

        if(target > dp[mid].endTime)
        {
            le = mid+1;
            nearestLeft = mid;
        }
        else if(target < dp[mid].endTime) ri = mid-1;
        else return mid;
    }

    return nearestLeft;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>startTime>>duration>>price;

            endTime = startTime+duration;
            dp[i] = action(startTime, endTime, price);
        }

        sort(dp, dp+n, cmp);

        sums[0] = dp[0].price;
        maxPos[0] = dp[0].price;

        //cout<<0<<" "<<dp[0].startTime<<" "<<dp[0].endTime<<" "<<dp[0].price<<" "<<-1<<" "<<dp[0].price<<" "<<maxPos[0]<<endl;

        for(int i = 1; i < n; i++)
        {
            sums[i] = sums[i-1]+dp[i].price;

            int nearest = binarySearch(dp[i].startTime), curSum = sums[nearest]+dp[i].price;
            maxPos[i] = max(maxPos[i-1], curSum);

            //cout<<i<<" "<<dp[i].startTime<<" "<<dp[i].endTime<<" "<<dp[i].price<<" "<<nearest<<" "<<curSum<<" "<<maxPos[i]<<endl;
        }

        cout<<maxPos[n-1]<<endl;
    }

    return 0;
}
