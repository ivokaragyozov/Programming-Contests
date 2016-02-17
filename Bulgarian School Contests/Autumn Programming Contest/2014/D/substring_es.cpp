/**
Ivo Karagyozov
Esenen 2014 D2 substring
*/
#include<iostream>
using namespace std;
int lettersA[26], lettersB[26];
int main()
{
    string a, b;
    cin>>a>>b;
    string ans;
    for(int i=0; i<a.size(); i++)
    {
        int let=a[i]-'a';
        lettersA[let]++;
    }
    for(int i=0; i<b.size(); i++)
    {
        int let=b[i]-'a';
        lettersB[let]++;
    }
    for(int i=0; i<26; i++)
    {
        int brMin=min(lettersA[i], lettersB[i]);
        for(int j=0; j<brMin; j++)
        {
            char let=(char)(i+'a');
            ans=ans+let;
        }
    }
    cout<<ans<<endl;
    return 0;
}
