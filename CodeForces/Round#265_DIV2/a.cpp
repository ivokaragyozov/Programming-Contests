#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, numberDec;
string number, number2;

int fromBinToDec(string s)
{
    int decimal = 0, p = 1;
    for(int i = s.size()-1; i >= 0; i--)
    {
        decimal += (s[i]-'0')*p;
        p *= 2;
    }
    return decimal;
}
string fromDecToBin(int a)
{
    string binary;
    while(a > 0)
    {
        binary += (char)(a%2+'0');
        a /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>number;
    numberDec = fromBinToDec(number);
    number2 = fromDecToBin(numberDec+1);
    for(int i = 0; i < )
}
