#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

const int maxN = 5 * 1e5;

bool isStable;
int n, a[maxN + 5], a1[maxN + 5], firstOne, lastOne, cnt, cntSteps, firstOne1, lastOne1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i] == 1 && firstOne == -1) firstOne = i;
        if(a[i] == 1) lastOne = i;
    }

    while(1)
    {
        for(int i = firstOne; i <= lastOne; i++)
        {
            if(i == 0 || i == n - 1) continue;
            cnt = 0;
            for(int j = i - 1; j <= i + 1; j++)
            {
                cnt += a[j];
            }
            if(cnt >= 2) a1[i] = 1;
            else a1[i] = 0;
        }
        isStable = true;
        firstOne1 = -1;
        for(int i = firstOne; i <= lastOne; i++)
        {
            if(i == 0 || i == n - 1) continue;

            if(a[i] != a1[i])
            {
                a[i] = a1[i];
                isStable = false;
            }
            if(a1[i] == 1)
            {
                if(firstOne1 == -1) firstOne1 = i;
                lastOne1 = i;
            }
        }

        firstOne = firstOne1;
        lastOne = lastOne1;

        if(isStable) break;
        cntSteps++;
        if(cntSteps > 1400) break;
    }

    cout<<cntSteps<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
