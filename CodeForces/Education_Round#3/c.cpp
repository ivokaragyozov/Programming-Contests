#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

int n, a[maxN], sum, x, y, need, cnt;
priority_queue<int> smallest, biggest;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];

        smallest.push(-a[i]);
        biggest.push(a[i]);
        sum += a[i];
    }

    if(sum % n == 0) need = 0;
    else need = 1;

    while(1)
    {
        x = biggest.top();
        y = -smallest.top();
        biggest.pop();
        smallest.pop();

        if(x - y == need) break;
        else
        {
            x--;
            y++;
            biggest.push(x);
            smallest.push(-y);
            cnt++;
        }
    }

    cout<<cnt<<endl;
    return 0;
}
