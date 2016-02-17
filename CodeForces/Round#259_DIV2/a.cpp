#include <iostream>
#define endl '\n'
using namespace std;

int n, cntStars, cntD;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    cntStars = (n - 1) / 2;
    cntD = 1;
    for(int i = 0; i <= n / 2; i++)
    {
        for(int j = 0; j < cntStars; j++) cout<<"*";
        for(int j = 0; j < cntD; j++) cout<<"D";
        for(int j = 0; j < cntStars; j++) cout<<"*";
        cout<<endl;

        cntD += 2;
        cntStars--;
    }

    cntStars = 1;
    cntD = n - 2;
    for(int i = n / 2 + 1; i < n; i++)
    {
        for(int j = 0; j < cntStars; j++) cout<<"*";
        for(int j = 0; j < cntD; j++) cout<<"D";
        for(int j = 0; j < cntStars; j++) cout<<"*";
        cout<<endl;

        cntD -= 2;
        cntStars++;
    }

    return 0;
}
