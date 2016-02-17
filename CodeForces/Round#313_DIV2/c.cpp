#include <iostream>
#define endl '\n'
using namespace std;

int a1, a2, a3, a4, a5, a6;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a1>>a2>>a3>>a4>>a5>>a6;

    cout<<(a1+a2+a3)*(a1+a2+a3)-a1*a1-a3*a3-a5*a5<<endl;
    return 0;
}
