#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, p, q, cntP = -1, cntQ, ind;
string s, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>p>>q>>s;
    for(int i = 0; i <= 100; i++)
    {
        if((n - p * i) % q == 0 && n - p * i >= 0)
        {
            cntP = i;
            cntQ = (n - p * i) / q;
            break;
        }
    }

    if(cntP == -1)
    {
        cout<<-1<<endl;
        return 0;
    }

    for(int i = 0; i < cntP; i++)
    {
        ans += s.substr(ind, p) + "\n";
        ind += p;
    }
    for(int i = 0; i < cntQ; i++)
    {
        ans += s.substr(ind, q) + "\n";
        ind += q;
    }

    cout<<cntP + cntQ<<endl<<ans;
    return 0;
}
