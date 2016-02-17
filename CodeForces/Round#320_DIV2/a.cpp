#include <iostream>
#define endl '\n'
using namespace std;

int n, answer, p = 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    while(n)
    {
        if(n & 1) answer++;

        n = n>>1;
    }

    cout<<answer<<endl;
    return 0;
}
