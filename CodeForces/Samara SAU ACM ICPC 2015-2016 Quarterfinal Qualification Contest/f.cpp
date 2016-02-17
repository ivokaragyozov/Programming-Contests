#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5, maxM = 1e5;

int n, m, currCnt, ans;
string table[maxN];
vector<int> nums;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>table[i];
    }

    for(int i = 0; i < n; i++)
    {
        currCnt = 0;

        for(int j = 0; j < m; j++)
        {
            if(table[i][j] == '.') currCnt++;
            else
            {
                if(currCnt > 0) nums.push_back(currCnt);
                currCnt = 0;
            }
        }


        if(currCnt > 0) nums.push_back(currCnt);
    }
    for(int j = 0; j < m; j++)
    {
        currCnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(table[i][j] == '.') currCnt++;
            else
            {
                if(currCnt > 0) nums.push_back(currCnt);
                currCnt = 0;
            }
        }


        if(currCnt > 0) nums.push_back(currCnt);
    }

    sort(nums.begin(), nums.end());

    int maxNM = max(n, m);
    for(int i = 1; i <= maxNM; i++)
    {
        ans = 0;

        for(int j = nums.size() - 1; j >= 0; j--)
        {
            if(nums[j] >= i) ans += nums[j] - i + 1;
            else break;
        }

        if(i == 1) ans /= 2;

        cout<<ans<<" ";
    }

    return 0;
}
