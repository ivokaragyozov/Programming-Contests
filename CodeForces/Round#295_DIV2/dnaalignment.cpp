#include<iostream>
using namespace std;
int let[26];
long long numString(string s)
{
    int brlet;
    for(int i=0; i<s.size(); i++)
    {
        if(let[i]==0)
        {
            brlet++;
            let[i]++;
        }
    }
    int siz=s.size();
    if(brlet!=siz)
    {
        return siz;
    }
    else
    {
        return
    }
}
int main()
{
    int n;
    string s;
    cin>>n>>s;

}
