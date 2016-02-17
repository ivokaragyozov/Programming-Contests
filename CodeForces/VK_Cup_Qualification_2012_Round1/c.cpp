#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

int n, indPath = 1;
string s, t, p;
stack<string> path;

void emptyPath()
{
    while(!path.empty())
    {
        path.pop();
    }
}
void printPath()
{
    stack<string> pathCopy;

    while(!path.empty())
    {
        pathCopy.push(path.top());
        path.pop();
    }

    while(!pathCopy.empty())
    {
        cout<<"/"<<pathCopy.top();

        path.push(pathCopy.top());
        pathCopy.pop();
    }
    cout<<"/"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>s;

        if(s == "pwd") printPath();
        else
        {
            cin>>t;

            for(int j = 0; j < t.size(); j++)
            {
                if(t[j] == '/')
                {
                    if(p == "") emptyPath();
                    else if(p == "..") pemath.pop();
                    else path.push(p);
                    p = "";
                    continue;
                }
                else p += t[j];
            }
            if(p == "") emptyPath();
            else if(p == "..") path.pop();
            else path.push(p);
            p = "";
        }
    }
}
