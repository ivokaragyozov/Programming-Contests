#include <iostream>
#define endl '\n'
using namespace std;

const int maxHeight = 1e6;

int n, a, ans = 0, arrows[maxHeight + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        if(arrows[a] != 0)
        {
            arrows[a]--;
            if(a - 1 > 0) arrows[a - 1]++;
        }
        else
        {
            ans++;
            if(a - 1 > 0) arrows[a - 1]++;
        }
    }

    cout<<ans<<endl;
    return 0;
}
