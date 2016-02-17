#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 2005;

long long n, k, x[maxN] = {-3000}, y[maxN]= {-3000}, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 1; i < n; i++)
    {
        ans += i;
        x[i] = x[i - 1];
        y[i] = y[i - 1] - 1;
    }

    if(ans <= k) cout<<"no solution"<<endl;
    else
    {
        for(int i = 0; i < n; i++)
        {
            cout<<x[i]<<" "<<y[i]<<endl;
        }
    }

    return 0;
}
