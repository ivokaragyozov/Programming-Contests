#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

char buf;
int n, maxDepth = 1, len1, len2;
string s, name1, name2;
map<string, int> depth;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    cin.get(buf);

    depth["polycarp"] = 1;
    for(int i = 0; i < n; i++)
    {
        getline(cin, name1, ' ');
        getline(cin, s, ' ');
        getline(cin, name2);

        len1 = name1.size();
        len2 = name2.size();
        for(int i = 0; i < len1; i++)
        {
            if(name1[i] >= 'A' && name1[i] <= 'Z') name1[i] = name1[i] - 'A' + 'a';
        }
        for(int i = 0; i < len2; i++)
        {
            if(name2[i] >= 'A' && name2[i] <= 'Z') name2[i] = name2[i] - 'A' + 'a';
        }

        //cout<<name1<<" "<<name2<<endl;

        depth[name1] = depth[name2] + 1;
        //cout<<name2<<" "<<depth[name2]<<endl;
        //cout<<name1<<" "<<depth[name1]<<endl;

        if(depth[name1] > maxDepth) maxDepth = depth[name1];
    }

    cout<<maxDepth<<endl;
    return 0;
}
