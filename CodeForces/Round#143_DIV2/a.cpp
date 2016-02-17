#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1000;

int n, problem, currSum, answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        currSum = 0;
        for(int j = 0; j < 3; j++)
        {
            cin>>problem;

            currSum += problem;
        }

        if(currSum >= 2) answer++;
    }

    cout<<answer<<endl;
    return 0;
}
