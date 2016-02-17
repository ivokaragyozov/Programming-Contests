#include <iostream>
#define endl '\n'
using namespace std;

int k, sum[1000005], answer, cnt[1000005];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k>>s;

    int len = s.size();
    for(int i = 0; i < len; i++)
    {
        sum[i] = (s[i]-'0');
        if(i > 0) sum[i] += sum[i-1];
    }

    cnt[0] = 1;

    for(int i = 0; i < len; i++)
    {
        cnt[sum[i]]++;
        if(sum[i] < k) continue;

        answer += cnt[sum[i]-k];
    }

    cout<<answer<<endl;
    return 0;
}
