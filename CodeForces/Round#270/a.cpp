#include <iostream>
#define endl '\n'
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    if(n % 2 == 0)
    {
        cout<<4<<" "<<n - 4<<endl;
    }
    else
    {
        cout<<9<<" "<<n - 9<<endl;
    }

    return 0;
}
