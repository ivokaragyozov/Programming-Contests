#include<iostream>
using namespace std;
int br[26], ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(i%2==0)
        {
            br[s[i]-'a']++;
        }
        else
        {
            if(br[s[i]-'A']==0)ans++;
            else br[s[i]-'A']--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
