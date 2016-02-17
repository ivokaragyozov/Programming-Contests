#include <iostream>
#define endl '\n'
using namespace std;

int n, k, l, c, d, p, nl, np;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    cout<<min(k*l/nl, min(c*d, p/np))/n<<endl;
    return 0;
}
