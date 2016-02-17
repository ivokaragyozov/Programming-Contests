/**
Ivo Karagyozov
Esenen 2012 D1 number
*/
#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int br=0;
    if(s[0]=='0')
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<s.size()/2;i++)
    {
        int raz = s.size()-i-1;
        if(i+1<raz && s[i+1]!='0')br++;
        else if(i+1==raz)
        {
            string first=s.substr(0, i), second=s.substr(i+1,s.size());
            if(first<second && second[0]!='0')br++;
        }
    }
    cout<<br<<endl;
}
