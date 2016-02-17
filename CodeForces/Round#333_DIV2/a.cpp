#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

unsigned long long n, x, m, y, num1, num2, power, a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;
    power = 1;
    for(int i = 0; i < n - 1; i++)
    {
        power *= x;
    }
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        num1 += a * power;
        power /= x;
    }

    cin>>m>>y;
    power = 1;
    for(int i = 0; i < m - 1; i++)
    {
        power *= y;
    }
    for(int i = 0; i < m; i++)
    {
        cin>>a;

        num2 += a * power;
        power /= y;
    }

    if(num1 < num2) cout<<"<"<<endl;
    else if(num1 == num2) cout<<"="<<endl;
    else cout<<">"<<endl;
    return 0;
}
