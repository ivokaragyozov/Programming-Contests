/**
Ivo Karagyozov
NOI3 2012 C1 div
*/
#include <iostream>
#define endl '\n'
using namespace std;

string n;

string divide(string s, int div)
{
    int ind = 1, part = s[0]-'0';
    bool p = false;
    string answer;

    while(ind < s.size())
    {
        if(part < div)
        {
            if(p && answer.size() != 0)
            {
                answer += '0';
            }
            part = part*10+(s[ind]-'0');
            ind++;
            p = true;
        }
        else
        {
            int tmp = part/div;
            part %= div;
            answer += (char)(tmp+'0');
            p = false;
        }
    }
    if(part%div == 0)
    {
        int tmp = part/div;
        part = 0;
        answer += (char)(tmp+'0');
    }
    if(part)
    {
        return "-1";
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=2; i<2001; i++)
    {
        string div = divide(n, i);
        if(div != "-1")
        {
            cout<<i<<" "<<div<<endl;
        }
    }
    return 0;
}
