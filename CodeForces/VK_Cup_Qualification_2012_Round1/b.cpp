#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

int n, currGroup, cnt1, cnt2, cnt3, cnt4, answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>currGroup;

        if(currGroup == 1) cnt1++;
        else if(currGroup == 2) cnt2++;
        else if(currGroup == 3) cnt3++;
        else cnt4++;
    }

    answer = cnt4;

    if(cnt3 >= cnt1)
    {
        answer += cnt1;
        cnt3 -= cnt1;
        cnt1 = 0;

        answer += cnt3 + cnt2 / 2 + cnt2 % 2;
    }
    else
    {
        answer += cnt3;
        cnt1 -= cnt3;
        cnt3 = 0;

        answer += cnt2 / 2;
        cnt2 %= 2;

        if(cnt2 != 0)
        {
            answer++;

            cnt2 = 0;
            cnt1 -= 2;
        }

        if(cnt1 > 0)
        {
            answer += cnt1 / 4 + (cnt1 % 4 == 0 ? 0 : 1);
        }
    }

    cout<<answer<<endl;
    return 0;
}
