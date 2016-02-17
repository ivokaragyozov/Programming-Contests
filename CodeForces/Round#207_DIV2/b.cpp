#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int maxN = 100005;

bool white, red, blue;
int n, m, a[maxN], b[maxN], c[maxN], answer[maxN];
vector<int> dancers[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>a[i]>>b[i]>>c[i];

        if(i == 0)
        {
            answer[a[i]] = 1;
            answer[b[i]] = 2;
            answer[c[i]] = 3;
        }

        dancers[a[i]].push_back(b[i]);
        dancers[a[i]].push_back(c[i]);
        dancers[b[i]].push_back(a[i]);
        dancers[b[i]].push_back(c[i]);
        dancers[c[i]].push_back(a[i]);
        dancers[c[i]].push_back(b[i]);
    }

    for(int i = 1; i < m; i++)
    {
        if(answer[a[i]] == 0)
        {
            white = 0;
            red = 0;
            blue = 0;

            for(int j = 0; j < dancers[a[i]].size(); j++)
            {
                if(answer[dancers[a[i]][j]] == 1) white = 1;
                else if(answer[dancers[a[i]][j]] == 2) red = 1;
                else if(answer[dancers[a[i]][j]] == 3) blue = 1;
            }

            if(white == 0) answer[a[i]] = 1;
            else if(red == 0) answer[a[i]] = 2;
            else answer[a[i]] = 3;
        }
        if(answer[b[i]] == 0)
        {
            white = 0;
            red = 0;
            blue = 0;

            for(int j = 0; j < dancers[b[i]].size(); j++)
            {
                if(answer[dancers[b[i]][j]] == 1) white = 1;
                else if(answer[dancers[b[i]][j]] == 2) red = 1;
                else if(answer[dancers[b[i]][j]] == 3) blue = 1;
            }

            if(white == 0) answer[b[i]] = 1;
            else if(red == 0) answer[b[i]] = 2;
            else answer[b[i]] = 3;
        }
        if(answer[c[i]] == 0)
        {
            white = 0;
            red = 0;
            blue = 0;

            for(int j = 0; j < dancers[c[i]].size(); j++)
            {
                if(answer[dancers[c[i]][j]] == 1) white = 1;
                else if(answer[dancers[c[i]][j]] == 2) red = 1;
                else if(answer[dancers[c[i]][j]] == 3) blue = 1;
            }

            if(white == 0) answer[c[i]] = 1;
            else if(red == 0) answer[c[i]] = 2;
            else answer[c[i]] = 3;
        }
    }

    cout<<answer[1];
    for(int i = 2; i <= n; i++)
    {
        cout<<" "<<answer[i];
    }
    cout<<endl;
    return 0;
}
