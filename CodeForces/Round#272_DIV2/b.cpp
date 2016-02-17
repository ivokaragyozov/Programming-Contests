#include <iostream>
#include <iomanip>
#include <cmath>
#define endl '\n'
using namespace std;

double paskal[15][15], pows[15];
int cntPlus, cntQuestions;
string s, t;

void preCompute()
{
    paskal[0][0] = 1.0;
    pows[0] = 1.0;

    for(int i = 1; i <= 10; i++)
    {
        pows[i] = 2 * pows[i - 1];

        paskal[i][0] = 1.0;
        paskal[i][i] = 1.0;
        for(int j = 1; j < i; j++)
        {
            paskal[i][j] = paskal[i - 1][j - 1] + paskal[i - 1][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preCompute();
    cin>>s>>t;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '+') cntPlus++;
    }
    for(int i = 0; i < t.size(); i++)
    {
        if(t[i] == '+') cntPlus--;
        else if(t[i] == '?') cntQuestions++;
    }

    if(cntPlus > cntQuestions || cntPlus < 0)
    {
        cout<<0<<endl;
        return 0;
    }

    cout<<fixed<<setprecision(9);
    cout<<paskal[cntQuestions][cntPlus] / pows[cntQuestions]<<endl;
    return 0;
}
