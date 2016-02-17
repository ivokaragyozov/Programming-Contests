#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int n, a, limak, answer;
priority_queue<int> candidates;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        if(i == 0) limak = a;
        else
        {
            candidates.push(a);
        }
    }

    while(1)
    {
        int top = candidates.top();
        candidates.pop();

        if(top < limak) break;
        else
        {
            limak++;
            answer++;
            top--;

            candidates.push(top);
        }
    }

    cout<<answer<<endl;
    return 0;
}
