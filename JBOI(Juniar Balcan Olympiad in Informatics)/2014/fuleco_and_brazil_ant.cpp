/**
Ivo Karagyozov
JBOI 2014 1.2 fuleco_and_brazil_ant
*/
#include <iostream>
#define endl '\n'
using namespace std;

int a, b, cntBranches, curDep, minDep;
string traversal;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b>>traversal;
    for(int i = min(a, b); i < max(a, b); i++)
    {
        if(traversal[i] == 'U') curDep++;
        else
        {
            curDep--;
            if(curDep < minDep) minDep = curDep;
        }
    }

    cout<<-minDep + (curDep - minDep)<<endl;
    return 0;
}
