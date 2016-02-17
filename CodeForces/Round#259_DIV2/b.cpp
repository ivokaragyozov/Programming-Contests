#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

int n, a[maxN], minA = INT_MAX, indMin, ans = 0, currInd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];

        if(a[i] < minA)
        {
            minA = a[i];
            indMin = i;
        }
    }

    currInd = indMin;
    while(a[currInd] == a[(currInd - 1 + n) % n] && (currInd - 1 + n) % n != 0) currInd = (currInd - 1 + n) % n;
    if(currInd == 1 && a[0] == minA) currInd = 0;

    indMin = currInd;
    currInd = (indMin + 1) % n;
    while(currInd != indMin)
    {
        if(a[currInd] < a[(currInd - 1 + n) % n])
        {
            cout<<-1<<endl;
            return 0;
        }

        currInd = (currInd + 1) % n;
    }

    if(indMin != 0) cout<<n - indMin<<endl;
    else cout<<0<<endl;
    return 0;
}
