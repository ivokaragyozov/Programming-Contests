#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

bool ans;
int n, k[maxN], b[maxN];
double x, y, x1, x2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x1>>x2;
    for(int i = 0; i < n; i++)
    {
        cin>>k[i]>>b[i];

        if(ans) continue;
        for(int j = sqrt(i); j >= 0; j--)
        {
            if(k[i] - k[j] == 0) continue;

            x = (double)(b[j] - b[i]) / (double)(k[i] - k[j]);

            if(x > x1 && x < x2)
            {
                ans = true;
                break;
            }
        }
    }

    if(ans) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
