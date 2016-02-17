#include <iostream>
#define endl '\n'
using namespace std;

bool currPlayer;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    if(min(n, m) % 2 == 0) cout<<"Malvika"<<endl;
    else cout<<"Akshat"<<endl;

    return 0;
}
