#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

int n, p;
string firstNames[maxN + 5], secondNames[maxN + 5], lastName;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>firstNames[i]>>secondNames[i];

        if(!lexicographical_compare(firstNames[i].begin(), firstNames[i].end(), secondNames[i].begin(), secondNames[i].end())) swap(firstNames[i], secondNames[i]);
    }

    for(int i = 0; i < n; i++)
    {
        cin>>p;
        p--;

        if(i == 0) lastName = firstNames[p];
        else
        {
            if(lexicographical_compare(lastName.begin(), lastName.end(), firstNames[p].begin(), firstNames[p].end())) lastName = firstNames[p];
            else if(lexicographical_compare(lastName.begin(), lastName.end(), secondNames[p].begin(), secondNames[p].end())) lastName = secondNames[p];
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;
    return 0;
}
