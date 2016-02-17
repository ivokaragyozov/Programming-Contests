#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int n, curr = 5, cnt = 1, x;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin>>n;
    while(1)
    {
        if(n - curr <= 0) break;

        n -= curr;
        curr *= 2;
        cnt *= 2;
    }

    //cout<<n<<" "<<cnt<<" "<<n / cnt<<endl;
    while(1)
    {
        if(n - cnt <= 0) break;

        n -= cnt;
        x++;
    }
    cout<<names[x]<<endl;
    return 0;
}
