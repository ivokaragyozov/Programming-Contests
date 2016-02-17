#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

struct leg
{
    int length, energy;
};

int n, cnt_by_length[100005], max_cnt = 0, number = 0;
leg legs[100005];
bool is_only_one = true;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>legs[i].length;
        cnt_by_length[legs[i].length]++;
        if(cnt_by_length[legs[i].length] > max_cnt)
        {
            max_cnt=cnt_by_length[legs[i].length];
            number = legs[i].length;
            is_only_one = true;
        }
        else if(cnt_by_length[legs[i].length] == max_cnt)
        {
            is_only_one = false;
        }
    }
    for(int i=0; i<n; i++)
    {
        cin>>legs[i].energy;
    }
}
bool cmp(leg a, leg b)
{
    return a.energy<b.energy;
}

int main()
{
    input();

    sort(legs, legs+n, cmp);
    if(is_only_one)
    {
        int need_to_cut = n-max_cnt*2+1, cutted = 0;
        if(need_to_cut <= 0)
        {
            cout<<0<<endl;
            return 0;
        }
        else
        {
            int ans = 0;
            for(int i=0; ; i++)
            {
                if(cutted == need_to_cut)
                {
                    break;
                }
                if(legs[i].length != number)
                {
                    ans += legs[i].energy;
                    cutted++;
                }
            }
            cout<<ans<<endl;
            return 0;
        }
    }
    else
    {

    }
}
