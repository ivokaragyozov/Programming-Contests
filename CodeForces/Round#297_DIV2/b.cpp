#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n, m;
    cin>>s>>n;
    for(int i=0; i<n; i++)
    {
        cin>>m;
        reverse(s.begin()+m-1, s.end()-m+1);
    }
    cout<<s<<endl;
}
