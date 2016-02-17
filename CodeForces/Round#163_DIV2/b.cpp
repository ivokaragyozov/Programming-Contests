#include <iostream>
using namespace std;

int n, t;
string q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>t>>q;
    for(int i = 0; i < t; i++)
    {
        for(int j = n-1; j > 0; j--)
        {
            if(q[j-1] == 'B' && q[j] == 'G')
            {
                swap(q[j], q[j-1]);
                j--;
            }
        }
    }
    cout<<q<<endl;
    return 0;
}
