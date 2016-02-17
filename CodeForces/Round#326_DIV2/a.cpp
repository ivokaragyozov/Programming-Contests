#include <iostream>
#define endl '\n'
using namespace std;

int n, a, p, currMin = 101, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>p;

        if(p < currMin) currMin = p;
        ans += currMin * a;
    }

    cout<<ans<<endl;
    return 0;
}
