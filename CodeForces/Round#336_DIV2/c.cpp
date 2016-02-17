#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5, maxA = 1e6 + 5;

struct beacon
{
    int a, b, cnt;

    beacon()
    {
        cnt = 0;
    }
};

bool line[maxA];
int n, destroyRange = 0, sums[maxA], sums2[maxN], currAns;
beacon beacons[maxN];

bool cmp(beacon x, beacon y)
{
    return x.a < y.a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>beacons[i].a>>beacons[i].b;
        line[beacons[i].a] = true;
    }

    sort(beacons, beacons + n, cmp);

    for(int i = 0; i <= beacons[n - 1].a; i++)
    {
        if(line[i])
        {
            if(i == 0) sums[i] = 1;
            else sums[i] = sums[i - 1] + 1;
        }
        else
        {
            if(i == 0) sums[i] = 0;
            else sums[i] = sums[i - 1];
        }
    }

    beacons[0].cnt = 0;
    for(int i = 1; i < n; i++)
    {
        //cout<<beacons[i].a<<" "<<sums[beacons[i].a - 1]<<endl;
        beacons[i].cnt = (beacons[i].a > 0 ? sums[beacons[i].a - 1] : 0) - (beacons[i].a - beacons[i].b > 0 ? sums[beacons[i].a - beacons[i].b - 1] : 0);
        //cout<<beacons[i].cnt<<endl;

        sums2[i] = sums2[i - beacons[i].cnt - 1] + beacons[i].cnt;
    }

    currAns = n;
    for(int i = 1; i <= n; i++)
    {
        if(sums2[i - 1] + n - i < currAns) currAns = sums2[i - 1] + n - i;
    }

    cout<<currAns<<endl;
    return 0;
}
