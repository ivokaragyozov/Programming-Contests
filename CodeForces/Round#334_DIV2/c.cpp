#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool hasMoreThan3, hasMoreThan2, hasTwoConsecutive, twoone, twoonetwo;
int n, cnt = 1, currCnt = 1, lastCnt = 0, lastCnt2 = 0;
string s;
vector<int> cnts;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>s;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] != s[i - 1])
        {
            cnts.push_back(currCnt);
            cnt++;
            currCnt = 1;
        }
        else currCnt++;
    }
    cnts.push_back(currCnt);

    if(cnts[0] >= 2 || cnts[cnts.size() - 1] >= 2) hasMoreThan2 = true;
    if(cnts.size() >= 2 && (cnts[1] >= 2 || cnts[cnts.size() - 2] >= 2)) twoone = true;

    for(int i = 0; i < cnts.size(); i++)
    {
        if(cnts[i] >= 3) hasMoreThan3 = true;
        if(i != 0 && cnts[i] >= 2 && cnts[i - 1] >= 2) hasTwoConsecutive = true;

        int j;
        for(j = i - 1; j >= 0; j--)
        {
            if(cnts[j] != 1) break;
        }
        if(j >= 0 && cnts[i] >= 2 && cnts[j] >= 2 && j != i - 1) twoonetwo = true;
    }

    if(hasMoreThan3) cnt += 2;
    else if(hasTwoConsecutive) cnt += 2;
    else if(twoonetwo) cnt += 2;
    else if(twoone) cnt++;
    else if(hasMoreThan2) cnt++;

    cout<<cnt<<endl;
    return 0;
}
