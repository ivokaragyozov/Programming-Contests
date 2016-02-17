#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool p;
unsigned long long l, r, k, curr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>l>>r>>k;
    curr = 1;

    if(k == 1)
    {
        if(k >= l && k <= r) cout<<1<<endl;
        else cout<<-1<<endl;

        return 0;
    }


    while(1)
    {
        if(curr < l) curr *= k;
        else if(curr >= l && curr <= r)
        {
            cout<<curr<<" ";
            p = true;
            curr *= k;
        }
        else break;
    }

    if(!p) cout<<-1<<endl;

    return 0;
}
