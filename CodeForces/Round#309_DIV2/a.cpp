#include <iostream>
#define endl '\n'
using namespace std;

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    cout<<(s.size()+1)*25+1<<endl;
    return 0;
}
