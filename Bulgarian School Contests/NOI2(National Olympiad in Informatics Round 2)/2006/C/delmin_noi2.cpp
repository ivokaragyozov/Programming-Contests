#include<iostream>i
-#include<cstdio>
using namespace std;

int n, sumdig[30005], sumtotal=0, sums[5400000];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++)
        {
            sumdig[i]+=s[j]-'0';
        }
        sumtotal+=sumdig[i];
    }
    sort(sumdig, sumdig+n);
    int ost=sumtotal%3;
    for(int i=0; i<n; i++)
    {
        for(int j=p; j>=sumdig[i]; j--)
        {
            if(sums[j]!=0)
            {
                sums[]
            }
        }
    }
}
