/**
Ivo Karagyozov
Esenen 2011 D3 frequency
*/
#include<iostream>
using namespace std;
int brLetters[26];
int main()
{
    string s;
    getline(cin, s, '@');
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='a' && s[i]<='z')brLetters[s[i]-'a']++;
        else if(s[i]>='A' && s[i]<='Z')brLetters[s[i]-'A']++;
    }
    int maxBr=0;
    for(int i=0; i<26; i++)
    {
        if(brLetters[i]>maxBr)maxBr=brLetters[i];
    }
    for(int i=maxBr; i>=1; i--)
    {
        for(int j=0; j<26; j++)
        {
            if(brLetters[j]>=i)cout<<(char)(j+'A');
            else cout<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<26; i++)cout<<"-";
    cout<<endl;
    for(int i=0; i<26; i++)cout<<(char)(i+'A');
    cout<<endl;
    return 0;
}
