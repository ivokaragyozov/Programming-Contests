#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

char buf;
int k, curNumber;

string toBin(int number)
{
    int p = 1;
    string bin;

    while(number > 0)
    {
        bin += (char)(number%2+'0');
        number /= 2;
    }

    reverse(bin.begin(), bin.end());
    return bin;
}
int toDec(string bin)
{
    int step = 1, len = bin.size(), dec = 0;

    for(int i = len-1; i >= 0; i--)
    {
        dec += (bin[i]-'0')*step;
        step *= 2;
    }

    return dec;
}
string rev(string s)
{
    string prefix = s.substr(0, k);
    s.erase(0, k);
    s += prefix;

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t, cur;
    int len;

    cin>>k;
    while(cin>>curNumber)
    {
        s = "";

        t = toBin(curNumber);
        while(t.size() < 8) t = '0'+t;
        s += t;
        cin>>buf>>curNumber;
        t = toBin(curNumber);
        while(t.size() < 8) t = '0'+t;
        s += t;
        cin>>buf>>curNumber;
        t = toBin(curNumber);
        while(t.size() < 8) t = '0'+t;
        s += t;
        cin>>buf>>curNumber;
        t = toBin(curNumber);
        while(t.size() < 8) t = '0'+t;
        s += t;

        s = rev(s);
        len = s.size();
        for(int i = 0; i < len; i += 8)
        {
            cur = s.substr(i, 8);
            cout<<char(toDec(cur));
        }
    }

    cout<<endl;
    return 0;
}
