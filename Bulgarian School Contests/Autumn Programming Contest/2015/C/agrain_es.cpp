#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n, l, d, x1, a, b, currCnt = 1;
set<int> points;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>l>>d>>x1>>a>>b;

    points.insert(-1);
    points.insert(l + 1);
    for(int i = 1; i <= n; i++)
    {
        //if(points.find(x1) != points.end()) continue;
        points.insert(x1);

        set<int>::iterator itlow = points.find(x1), itupp = points.upper_bound(x1 + 1);
        itlow--;
        int prev = *itlow, next = *itupp;

        //cout<<next<<" "<<prev<<" "<<currCnt<<endl;
        if(next - prev - 1 > d) currCnt--;
        if(next - x1 - 1 > d) currCnt++;
        if(x1 - prev - 1 > d) currCnt++;
        //cout<<currCnt<<endl;

        if(currCnt <= 0)
        {
            cout<<i<<endl;
            return 0;
        }

        x1 = ((long long)x1 * a + b) % (l + 1);
        //cout<<"x1 "<<i<<" "<<x1<<endl;
    }

    cout<<-1<<endl;
    return 0;
}
