#include <iostream>
#define endl '\n'
using namespace std;

long long a, b;
string aStr, bStr;

int stringCmp(string x, string y)
{
    if(x.size() == y.size())
    {
        if(x < y) return -1;
        else if(x > y) return 1;
        else return 0;
    }
    else if(x.size() > y.size()) return 1;
    else return -1;
}
long long stringToInt(string x)
{
    long long len = x.size(), ansInt = 0;

    for(int i = 0; i < len; i++)
    {
        ansInt = ansInt * 10 + (x[i] - '0');
    }

    return ansInt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>aStr>>bStr;
    if(stringCmp(aStr, bStr) == 1) swap(aStr, bStr);

    if(aStr.size() > 10)
    {
        cout<<0<<endl;
        return 0;
    }
    else if(bStr.size() > 10) bStr = "9999999999";

    a = stringToInt(aStr);
    b = stringToInt(bStr);


    return 0;
}
