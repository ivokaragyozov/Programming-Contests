#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct word
{
    string first;
    string second;
};
int cmp(word s, word t)
{
    if(s.first.size()!=t.first.size())return s.first.size()<t.first.size();
    else return s.first<t.first;
}
word words[3000];
int binaryS(string target, int n)
{
    int ri=0, le=n-1;
    if(le<0)return false;
    while(ri<=le)
    {
        int mid=(ri+le)/2;
        if((words[mid].first.size()<target.size()) || (words[mid].first.size()==target.size() && words[mid].first<target))
        {
            ri=mid+1;
        }
        else if((words[mid].first.size()>target.size()) || (words[mid].first.size()==target.size() && words[mid].first>target))
        {
            le=mid-1;
        }
        else return mid;
    }
    return -1;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        cin>>words[i].first>>words[i].second;
    }
    sort(words, words+m, cmp);
    string ans="";
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        int ind=binaryS(s, m);
        if(words[ind].first.size()<=words[ind].second.size())ans+=words[ind].first;
        else ans+=words[ind].second;
        if(i!=n-1)ans+=' ';
    }
    cout<<ans<<endl;
    return 0;
}
