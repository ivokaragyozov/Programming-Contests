#include <iostream>
#define endl '\n'
using namespace std;

int n, x, cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;
    for(int i = 1; i <= n; i++)
    {
        if(x%i == 0 && x/i <= n)
        {
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
