#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

struct number
{
    int cntTimes, firstMeeting, lastMeeting, diff;

    number()
    {
        cntTimes = 0;
        lastMeeting = 0;
        firstMeeting = 10000005;
        diff = 100000000;
    }
};

int n, arr[100005];
number numbers[1000005];

bool cmp(number a, number b)
{
    if(a.cntTimes != b.cntTimes) return a.cntTimes > b.cntTimes;
    else return a.diff < b.diff;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
        numbers[arr[i]].cntTimes++;
        if(i < numbers[arr[i]].firstMeeting)
        {
            numbers[arr[i]].firstMeeting = i;
        }
        if(i > numbers[arr[i]].lastMeeting)
        {
            numbers[arr[i]].lastMeeting = i;
        }

        numbers[arr[i]].diff = numbers[arr[i]].lastMeeting-numbers[arr[i]].firstMeeting+1;
    }

    sort(numbers, numbers+1000004, cmp);

    cout<<numbers[0].firstMeeting+1<<" "<<numbers[0].lastMeeting+1<<endl;
    return 0;
}
