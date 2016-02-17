#include <iostream>
using namespace std;

int n, m, cntDays;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    while(n > 0)
    {
        n--;
        cntDays++;
        if(cntDays%m == 0) n++;
    }
    cout<<cntDays<<endl;
    return 0;
}
