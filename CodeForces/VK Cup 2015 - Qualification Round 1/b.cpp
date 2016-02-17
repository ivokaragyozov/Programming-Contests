#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 200000;

int n, w[maxN + 5], h[maxN + 5], firstMax, secondMax, firstMaxInd, secondMaxInd, sumW, W, H;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>w[i]>>h[i];

        sumW += w[i];

        if(h[i] >= firstMax)
        {
            secondMax = firstMax;
            secondMaxInd = firstMaxInd;
            firstMax = h[i];
            firstMaxInd = i;
        }
        else if(h[i] > secondMax)
        {
            secondMax = h[i];
            secondMaxInd = i;
        }
    }

    for(int i = 0; i < n; i++)
    {
        W = sumW - w[i];
        H = (i == firstMaxInd ? secondMax : firstMax);

        if(n != n - 1) cout<<W * H<<" ";
        else cout<<W * H<<endl;
    }

    return 0;
}
