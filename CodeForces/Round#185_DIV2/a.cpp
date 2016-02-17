#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
string curr, preffix, suffix;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    getline(cin, curr);
    for(int i = 0; i < n; i++)
    {
        getline(cin, curr);

        if(curr.size() < 5)
        {
            cout<<"OMG>.< I don't know!"<<endl;
            continue;
        }

        preffix = curr.substr(0, 5);
        suffix = curr.substr(curr.size() - 5, 5);

        if(preffix == "miao." && suffix != "lala.") cout<<"Rainbow's"<<endl;
        else if(preffix != "miao." && suffix == "lala.") cout<<"Freda's"<<endl;
        else cout<<"OMG>.< I don't know!"<<endl;
    }

    return 0;
}
