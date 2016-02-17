#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

long long n, k, cntTimesLet[26], answer;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k>>s;
    for(int i = 0; i < n; i++)
    {
        cntTimesLet[s[i]-'A']++;
    }

    sort(cntTimesLet, cntTimesLet+26);
    for(int i = 25; i >= 0; i--)
    {
        if(k >= cntTimesLet[i])
        {
            answer += cntTimesLet[i]*cntTimesLet[i];
            k -= cntTimesLet[i];
        }
        else
        {
            answer += k*k;
            break;
        }
    }

    cout<<answer<<endl;
    return 0;
}
