#include <iostream>
#define endl '\n'
using namespace std;

int n, x1, y1, x2, y2, table[105][105], sum=0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        for(int a=x1; a<=x2; a++)
        {
            for(int b=y1; b<=y2; b++)
            {
                table[a][b]++;
            }
        }
    }
}

int main()
{
    input();
    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
        {
            sum+=table[i][j];
        }
    }
    cout<<sum<<endl;
    return 0;
}
