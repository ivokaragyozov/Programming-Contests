#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int number, dayOfWeek = 5, d = 1, m = 1, months[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, ans;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>number>>s>>s;

    while(d != 1 || m != 13)
    {
        if(s == "week" && dayOfWeek == number) ans++;
        else if(s == "month" && d == number) ans++;

        dayOfWeek++;
        if(dayOfWeek == 8) dayOfWeek = 1;

        d++;
        if(d > months[m])
        {
            d = 1;
            m++;
        }
    }


    cout<<ans<<endl;
    return 0;
}
