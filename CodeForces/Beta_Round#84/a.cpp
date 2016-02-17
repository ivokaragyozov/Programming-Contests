#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int cnt4, cnt7, cntLucky;
long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    while(n > 0)
    {
        if(n % 10 == 4) cnt4++;
        else if(n % 10 == 7) cnt7++;

        n /= 10;
    }

    cntLucky = cnt4 + cnt7;
    if(cntLucky == 4 || cntLucky == 7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
