/**
Ivo Karagyozov
Esenen 2014 C1 substrings
*/
#include <iostream>
#define endl '\n'
using namespace std;

int lenS, lenT, cntS[30], cntT[30];
long long ans, fact[20];
string s, t;

void generateFact(int last)
{
    fact[0] = 1;
    fact[1] = 1;

    for(int i = 2; i <= last; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>t;
    lenS = s.size();
    lenT = t.size();

    generateFact(lenS);

    for(int i = 0; i < lenS; i++)
    {
        cntS[s[i] - 'a']++;
    }
    for(int j = 0; j < lenT; j++)
    {
        cntT[t[j] - 'a']++;
    }


    for(int i = 0; i < 26; i++)
    {
        if(cntS[i] < cntT[i])
        {
            cout<<0<<endl;
            return 0;
        }
    }

    for(int i = 0; i <= lenS - lenT; i++)
    {
        ans += (fact[lenS - lenT] / fact[lenS - lenT - i]) * (i + 1);
    }

    cout<<ans<<endl;
    return 0;
}
