#include <iostream>
#define endl '\n'
using namespace std;

bool isInPeriod;
char ch;
int n, m, cntPeriods, cntDots, pos;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>s;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '.')
        {
            if(!isInPeriod) cntPeriods++;
            cntDots++;
            isInPeriod = true;
        }
        else
        {
            isInPeriod = false;
        }
    }

    for(int i = 0; i < m; i++)
    {
        cin>>pos>>ch;
        pos--;
        if(s[pos] == '.' && ch != '.')
        {
            if((pos > 0 && s[pos-1] == '.') && (pos < n-1 && s[pos+1] == '.'))
            {
                cntDots--;
                cntPeriods++;
            }
            else if((pos > 0 && s[pos-1] == '.') || (pos < n-1 && s[pos+1] == '.')) cntDots--;
            else
            {
                cntDots--;
                cntPeriods--;
            }
        }
        else if(s[pos] != '.' && ch == '.')
        {
            if((pos > 0 && s[pos-1] == '.') && (pos < n-1 && s[pos+1] == '.'))
            {
                cntDots++;
                cntPeriods--;
            }
            else if((pos > 0 && s[pos-1] == '.') || (pos < n-1 && s[pos+1] == '.')) cntDots++;
            else
            {
                cntDots++;
                cntPeriods++;
            }
        }

        s[pos] = ch;

        cout<<cntDots-cntPeriods<<endl;
    }
    return 0;
}
