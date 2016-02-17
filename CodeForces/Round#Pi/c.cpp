#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

long long n, k, a[200005], answer;
map<long long, long long> le, ri;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        ri[a[i]]++;
    }

    for(int i = 0; i < n; i++)
    {
        ri[a[i]]--;
        if(a[i]%k == 0) answer += le[a[i]/k]*ri[a[i]*k];
        le[a[i]]++;
    }

    cout<<answer<<endl;

    return 0;
}
