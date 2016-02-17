#include <iostream>
#define endl '\n'
using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    if(n == 1) cout<<m<<endl;
    else if(n-m >= m) cout<<m+1<<endl;
    else cout<<m-1<<endl;
}

