/**
Ivo Karagyozov
Zimni 2015 C2 worktime
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, currAns, maxAns, indAns, indOfTime;
string times[505], beg, en;

void generateTimes()
{
    string currTime = "012345";
    int h, m, s;

    do
    {
        h = (currTime[0] - '0') * 10 + (currTime[1] - '0');
        m = (currTime[2] - '0') * 10 + (currTime[3] - '0');
        s = (currTime[4] - '0') * 10 + (currTime[5] - '0');

        if(h <= 23 && m <= 59 && s <= 59) times[indOfTime++] = currTime;
    }
    while(next_permutation(currTime.begin(), currTime.end()));
}
int binarySearch(string target, string type)
{
    int le = 0, ri = indOfTime - 1, mid, nearestLeft =  0, nearestRight = 0;

    while(le <= ri)
    {
        mid = (le + ri) / 2;


        if(times[mid] < target)
        {
            nearestLeft = mid;
            le = mid + 1;
        }
        else if(times[mid] > target)
        {
            nearestRight = mid;
            ri = mid - 1;
        }
        else return mid;
    }

    if(type == "left") return nearestLeft;
    else return nearestRight;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    generateTimes();

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        currAns = 0;

        for(int j = 0; j < m; j++)
        {
            cin>>beg>>en;

            beg = beg.substr(0, 2) + beg.substr(3, 2) + beg.substr(6, 2);
            en = en.substr(0, 2) + en.substr(3, 2) + beg.substr(6, 2);

            int leftInd = binarySearch(beg, "right"), rightInd = binarySearch(en, "left");
            currAns += (rightInd - leftInd + 1);
        }

        if(currAns > maxAns)
        {
            maxAns = currAns;
            indAns = i + 1;
        }
    }

    cout<<indAns<<" "<<maxAns<<endl;
    return 0;
}
