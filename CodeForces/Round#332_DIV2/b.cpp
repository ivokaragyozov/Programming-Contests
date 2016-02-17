#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 100005, maxM = 100005;

int n, m, b, a, ans[maxM];
vector<int> f[maxN];
string answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        f[a].push_back(i);
    }

    for(int i = 0; i < m; i++)
    {
        cin>>b;

        if(f[b].empty())
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
        else if(f[b].size() > 1)
        {
            answer = "Ambiguity";
        }
        else ans[i] = f[b][0];
    }

    if(answer == "Ambiguity")
    {
        cout<<answer<<endl;
        return 0;
    }

    cout<<"Possible"<<endl;
    for(int i = 0; i < m; i++)
    {
        cout<<ans[i] + 1<<" ";
    }
    cout<<endl;
    return 0;
}
