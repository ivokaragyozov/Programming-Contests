#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a, indI, indJ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin>>a;

            if(a == 1)
            {
                indI = i;
                indJ = j;
            }
        }
    }

    cout<<abs(2 - indI) + abs(2 - indJ)<<endl;
    return 0;
}
