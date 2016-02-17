#include <iostream>
#define endl '\n'
using namespace std;

bool hasOne;
int n, a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        if(a == 1) hasOne = true;
    }

    cout<<(hasOne ? -1 : 1)<<endl;
    return 0;
}
