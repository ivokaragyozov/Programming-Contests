/**
Ivo Karagyozov
Esenen 2011 C3 company
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N=200005;
int gPeopleCount;
vector<int> gTree[N];

int gBr=1;

void order(int a, int b)
{
    gBr++;
    if(gBr==gPeopleCount)
    {
        cout<<gTree[a][b]<<endl;
        return;
    }
    else
    {
        cout<<gTree[a][b]<<" ";
    }

    for(int i=0;i<gTree[gTree[a][b]].size();i++)
    {
        order(gTree[a][b],i);
    }

    return;
}

int main()
{
    cin>>gPeopleCount;

    int person1,person2;
    for(int i=1;i<gPeopleCount;i++)
    {
        cin>>person1>>person2;
        gTree[person1].push_back(person2);
    }

    for(int i=1;i<=gPeopleCount;i++)
    {
        sort(gTree[i].begin(),gTree[i].end());
    }

    cout<<"1 ";

    for(int i=0;i<gTree[1].size();i++)
    {
        order(1,i);
    }

    return 0;
}
