#include <iostream>
#define endl '\n'
using namespace std;

int n, d[105], a, b, answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n-1; i++)
    {
        cin>>d[i];
    }
    cin>>a>>b;

    for(int i = a-1; i < b-1; i++)
    {
        answer += d[i];
    }

    cout<<answer<<endl;
    return 0;
}
