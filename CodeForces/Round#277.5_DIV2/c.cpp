#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int m, s;
string minNum, maxNum;

bool isPosToMakeTail(int len, int sum)
{
    return sum >= 0 && sum <= 9*len;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>s;

    int sum1 = s, sum2 = s;

    for(int i = 1; i <= m; i++)
    {
        for(int d = 0; d < 10; d++)
        {
            if((i > 1 || d > 0 || (m == 1 && d == 0)) && isPosToMakeTail(m-i, sum1-d))
            {
                minNum += (char)(d+'0');
                sum1 -= d;
                break;
            }
        }

        for(int d = 9; d >= 0; d--)
        {
            if(isPosToMakeTail(m-i, sum2-d))
            {
                maxNum += (char)(d+'0');
                sum2 -= d;
                break;
            }
        }

        if(minNum == "" || maxNum == "") break;
    }

    /*maxNum = minNum;
    reverse(maxNum.begin(), maxNum.end());

    if(maxNum[0] == '0') maxNum = minNum;*/

    if(minNum != "" && maxNum != "") cout<<minNum<<" "<<maxNum<<endl;
    else cout<<"-1 -1"<<endl;
    return 0;
}
