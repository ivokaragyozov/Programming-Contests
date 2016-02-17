#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 100;

int n, a[maxN + 5], firstInd = -1, lastInd = -1, answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];

        if(lastInd == -1 && a[i] == 1) firstInd = i;
        if(a[i] == 1) lastInd = i;
    }

    if(firstInd == -1)
    {
        cout<<0<<endl;
        return 0;
    }

    for(int i = firstInd; i <= lastInd; i++)
    {
        if(a[i] == 1) answer++;
        else
        {
            if(a[i + 1] == 1) answer++;
            else
            {
                while(a[i] == 0) i++;
                i--;
            }
        }
    }

    cout<<answer<<endl;
    return 0;
}
