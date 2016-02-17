#include <iostream>
#define endl '\n'
using namespace std;

int l, p, q;
double ans, cntSeconds, firstMeeting;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>l>>p>>q;
    cntSeconds = (double)l / (p + q);
    firstMeeting = cntSeconds * p;

    cout<<firstMeeting<<endl;
}
