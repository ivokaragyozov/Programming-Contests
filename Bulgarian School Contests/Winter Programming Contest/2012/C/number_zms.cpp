/**
Ivo Karagyozov
Zimni 2012 C3 number
*/
#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAXS = 900;
const int MAXP = 8100;

int t, minLen[MAXS+5][MAXP+5], lastDig[MAXS+5][MAXP+5], s, p;

void init()
{
    memset(minLen, -1, sizeof(minLen));
    for(int i=1; i<=9; i++)
    {
        minLen[i][i*i] = 1;
        lastDig[i][i*i] = i;
    }
    for(int i=2; i<=MAXS; i++)
    {
        for(int j=2; j<=MAXP; j++)
        {
            if(minLen[i][j] != -1)
            {
                continue;
            }
            for(int k=1; k<=9 && i - k >= 0 && j - k * k >= 0; k++)
            {
                if(minLen[i - k][j - k*k] != -1  && (minLen[i][j] == -1 || minLen[i - k][j - k*k] + 1 < minLen[i][j]))
                {
                    minLen[i][j] = minLen[i - k][j - k*k] + 1;
                    lastDig[i][j] = k;
                }
            }

        }
    }
}
void print(int a, int b)
{
    int i = a, j = b, answer[105], ind = 0;
    while(!(i == 0 || j == 0))
    {
        answer[ind++] = lastDig[i][j];

        i -= answer[ind-1];
        j -= answer[ind-1]*answer[ind-1];
    }

    for(int k=0; k<ind; k++)
    {
        cout<<answer[k];
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    init();
    for(int i=0; i<t; i++)
    {
        cin>>s>>p;
        if(s > MAXS || p > MAXP || minLen[s][p] == -1 || minLen[s][p] > 100)
        {
            cout<<"No solution"<<endl;
        }
        else
        {
            print(s, p);
        }
    }
}
