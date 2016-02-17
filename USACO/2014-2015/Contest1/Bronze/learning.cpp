/**
Ivo Karagyozov
2/13 correct
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct cow
{
    bool isSport;
    int weight;
    cow()
    {

    }
    cow(bool a, int b)
    {
        isSport=a;
        weight=b;
    }
};

int n, a, b, ans=0;
vector<cow> v;

bool cmp(cow a, cow b)
{
    if(a.weight!=b.weight)return a.weight<b.weight;
    else return a.isSport>b.isSport;
}

int main()
{
    freopen("learning.in", "r", stdin);
    freopen("learning.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a>>b;
    for(int i=0; i<n; i++)
    {
        string s;
        int weight;
        cin>>s>>weight;
        bool p=false;
        if(s=="S")p=true;
        v.push_back(cow(p, weight));
    }
    sort(v.begin(), v.end(), cmp);
    int i=0;
    while(v[i].weight<a)i++;
    if(v[i].isSport==true)
    {
        ans+=(v[i].weight-a+1);
    }
    for(; i<v.size()-1; i++)
    {
        if(v[i].isSport==true && v[i+1].isSport==true)
        {
            ans+=v[i+1].weight-v[i].weight;
        }
        else if(v[i].isSport==true && v[i+1].isSport==false)
        {
            int j=v[i].weight+1;
            while(j-v[i].weight<=v[i+1].weight-j)
            {
                ans++;
                j++;
            }
        }
        else if(v[i].isSport==false && v[i+1].isSport==true)
        {
            int j=v[i+1].weight;
            while(v[i+1].weight-j<=j-v[i].weight)
            {
                ans++;
                j--;
            }
        }
    }
    if(v[n-1].isSport==true)
    {
        ans+=(b-v[n-1].weight);
    }
    cout<<ans<<endl;
    return 0;
}
