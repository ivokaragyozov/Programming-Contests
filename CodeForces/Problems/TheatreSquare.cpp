#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int n, m, a;
double cnt_on_width, cnt_on_height;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>a;
    cnt_on_width = (double)n/(double)a;
    cnt_on_height = (double)m/(double)a;

    cnt_on_width = ceil(cnt_on_width);
    cnt_on_height = ceil(cnt_on_height);

    cout<<(long long)cnt_on_width*(long long)cnt_on_height<<endl;
    return 0;
}

