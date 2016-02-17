#include <iostream>
#define endl '\n'
using namespace std;

string s;
int day, month, year, author, sum, curSum, m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getDay(string t)
{
    return 10*(t[0]-'0')+(t[1]-'0');
}
int getMonth(string t)
{
    return 10*(t[2]-'0')+(t[3]-'0');
}
int getYear(string t)
{
    int y = 100*(t[4]-'0')+10*(t[5]-'0')+(t[6]-'0');

    if(y <= 599) y += 2000;
    else y += 1000;

    return y;
}
int getAuthor(string t)
{
    return t[7]-'0';
}
int getSum(string t)
{
    return t[8]-'0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 3; i++)
    {
        cin>>s;

        day = getDay(s);
        month = getMonth(s);
        year = getYear(s);
        author = getAuthor(s);
        sum = getSum(s);

        curSum = 0;
        for(int j = 0; j < 8; j++)
        {
            int dig = s[j]-'0';

            curSum += dig*dig;
        }

        if((year%4 == 0 && year%100 != 0) || year%400 == 0) m[2] = 29;
        else m[2] = 28;

        if(month > 12 || day == 0 || (author != 1 && author != 6 && author != 9) || day > m[month] || curSum%7 != sum) cout<<0<<endl;
        else cout<<1<<endl;
    }

    return 0;
}
