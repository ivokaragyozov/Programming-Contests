#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, x[5], y[5], w = -1, h = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i];

        for(int j = i - 1; j >= 0; j--)
        {
            if(x[i] != x[j] && y[i] != y[j])
            {
                w = abs(x[i] - x[j]);
                h = abs(y[i] - y[j]);
            }
        }
    }

    cout<<w * h<<endl;
    return 0;
}
