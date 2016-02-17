#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 8;

int n, m, currCnt, a[maxN + 5], maxSum;

int sum(int arr[])
{
    int curr, ans = 0;

    for(int i = 0; i < n; i++)
    {
        curr = arr[i];
        ans += curr;
        for(int j = i + 1; j < n; j++)
        {
            curr = min(curr, arr[j]);
            ans += curr;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    sort(a, a + n);

    do
    {
        if(sum(a) > maxSum) maxSum = sum(a);
    }
    while(next_permutation(a, a + n));

    sort(a, a + n);

    do
    {
        if(sum(a) == maxSum) currCnt++;

        if(currCnt == m) break;
    }
    while(next_permutation(a, a + n));

    for(int i = 0; i < n; i++)
    {
        cout<<a[i];
        if(i == n - 1) cout<<endl;
        else cout<<" ";
    }

    return 0;
}
