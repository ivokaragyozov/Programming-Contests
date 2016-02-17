#include <iostream>
#define endl '\n'
using namespace std;

int n, m, a, b;
double winning;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>a>>b;
    winning = (double)b/m;

    if(winning >= a) cout<<n*a<<endl;
    else cout<<(n/m)*b+min((n-(n/m)*m)*a, b)<<endl;

    return 0;
}
