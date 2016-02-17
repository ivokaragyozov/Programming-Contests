#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long maxN = 1e10 + 5;

long long t, low, high, k, squeares[10000], ind, currCnt;
vector<long long> v[10000];

int binarySearch(int target, int l, string type)
{
    int le = 0, ri = v[l].size() - 1, mid, nearestLeft = -1, nearestRight = -1;

    while(le <= ri)
    {
        mid = (le + ri) / 2;

        if(v[l][mid] > target)
        {
            nearestRight = mid;
            ri = mid - 1;
        }
        else if(v[l][mid] < target)
        {
            nearestLeft = mid;
            le = mid + 1;
        }
        else return mid;
    }

    if(type == "right") return nearestRight;
    else return nearestLeft;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cout<<sqrt(maxN)<<endl;

    for(long long i = 1; i < sqrt(maxN); i++)
    {
        squeares[ind++] = i * i;

        for(long long j = 2; j <= sqrt(i); j++)
        {
            if(i * i % j == 0)
            {
                if(i * i / j != j) currCnt += 2;
                else currCnt++;
            }
        }

        v[currCnt].push_back(i * i);
    }

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>low>>high>>k;

        cout<<binarySearch(low, k, "right") - binarySearch(high, k, "left") + 1<<endl;
    }

    return 0;
}
