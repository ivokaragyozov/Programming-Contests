#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

int v, d[10], len, rest, minDigitLitters = INT_MAX, minDigit, maxDigit = 0;
string answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>v;
    for(int i = 1; i < 10; i++)
    {
        cin>>d[i];
        if(minDigitLitters >= d[i])
        {
            minDigitLitters = d[i];
            minDigit = i;
        }
    }

    len = v/minDigitLitters;
    rest = v%minDigitLitters;

    for(int i = 0; i < len; i++)
    {
        if(rest == 0)
        {
            cout<<minDigit;
        }
        else
        {
            rest += minDigitLitters;
            for(int j = 1; j < 10; j++)
            {
                if(d[j] <= rest) maxDigit = j;
            }
            rest -= d[maxDigit];
            cout<<maxDigit;
        }
    }

    if(len > 0) cout<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
