#include <iostream>
#define endl '\n'
using namespace std;

int na, nb, k, m, a[100005], b[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>na>>nb>>k>>m;
    for(int i = 0; i < na; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i < nb; i++)
    {
        cin>>b[i];
    }

    if(a[k-1] < b[nb-m]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
