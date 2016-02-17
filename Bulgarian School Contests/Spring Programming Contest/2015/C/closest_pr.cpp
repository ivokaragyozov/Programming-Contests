/**
Ivo Karagyozov
Proleten 2015 C2 closest
*/
#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
const long long VAL_MAX=(1LL<<63)-1;
using namespace std;

long long n, m, ans=1;
int numbers[]={2, 3, 5, 7, 11, 13, 17, 19};

void recurse(long long current, int ind, long long a)
{
    if(current>=a || ind>=8 || VAL_MAX/numbers[ind]<current)
    {
        if(abs(a-current)<abs(a-ans))
        {
            ans=current;
        }
        else if(abs(a-current)==abs(a-ans))
        {
            ans=min(ans, current);
        }
        return;
    }
    recurse(current*numbers[ind], ind, a);
    recurse(current, ind+1, a);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    ans=1;
    recurse(1, 0, n);
    cout<<ans<<" ";
    recurse(1, 0, m);
    cout<<ans<<endl;
    return 0;
}
