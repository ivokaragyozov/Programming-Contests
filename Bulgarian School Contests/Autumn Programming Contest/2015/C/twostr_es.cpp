/**
Ivo Karagyozov
Esenen 2015 C1 twostr
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s, t, num1, maxNum, num2, minNum;

bool strCompare(string a, string b)
{
    if(a.size() != b.size()) return a.size() > b.size();
    else return a > b;
}
string subtract(string a, string b)
{
    bool p = false;
    int curr, prenos = 0;
    string res, need;

    if(strCompare(b, a))
    {
        swap(a, b);
        p = true;
    }

    need.resize(a.size() - b.size(), '0');
    b = need + b;

    res = a;

    for(int i = a.size() - 1; i >= 0; i--)
    {
        curr = (a[i] - '0') - (b[i] - '0') - prenos;

        if(curr < 0)
        {
            curr += 10;
            prenos = 1;
        }
        else prenos = 0;

        res[i] = (char)(curr + '0');
    }

    int i = b.size();
    while(prenos == 1)
    {
        curr = (a[i] - '0') - prenos;

        if(curr < 0)
        {
            curr += 10;
            prenos = 1;
        }
        else prenos = 0;

        res[i] = (char)(prenos + '0');
        i++;
    }
    i = 0;
    while(res[i] == '0') i++;
    res = res.substr(i);

    if(p) res = '-' + res;

    return (res == "" ? "0" : res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>t;

    int lenS = s.size(), lenT = t.size();
    for(int i = 0; i < lenS; i++)
    {
        num1 = "";
        if(maxNum != "" && s[i] < maxNum[0]) continue;
        for(int j = 0; j < lenS; j++)
        {
            num1 += s[(i + j) % lenS];
        }

        if(strCompare(num1, maxNum) || maxNum == "") maxNum = num1;
    }

    for(int i = 0; i < lenT; i++)
    {
        num2 = "";

        if(minNum != "" && t[i] > minNum[0]) continue;
        for(int j = 0; j < lenT; j++)
        {
            num2 += t[(i + j) % lenT];
        }

        if((strCompare(minNum, num2) || minNum == "") && num2[0] != '0') minNum = num2;
    }

    cout<<subtract(maxNum, minNum)<<endl;
    return 0;
}
