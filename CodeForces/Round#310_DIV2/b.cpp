#include <iostream>
#define endl '\n'
using namespace std;

int n, active_tooth[1005];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>active_tooth[i];
    }
}

int main()
{
    input();
    while(active_tooth[0] != 0)
    {
        for(int i=0; i<n; i++)
        {
            int active = active_tooth[i];
            if(i%2 == 0)
            {
                active++;
                active_tooth[i] = active%n;
            }
            else
            {
                active--;
                if(active < 0)
                {
                    active = n-1;
                }
                active_tooth[i] = active;
            }
        }
    }

    bool is_real = true;
    for(int i=1; i<n; i++)
    {
        if(active_tooth[i] != active_tooth[i-1]+1)
        {
            is_real = false;
            break;
        }
    }
    if(is_real)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
