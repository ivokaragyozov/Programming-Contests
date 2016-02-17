#include <iostream>
#define endl '\n'
using namespace std;

bool p1, p2, p3, p4;
int n, books[55][55], visible;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>books[i][j];
        }
    }

    visible = n*n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(books[i][j] == 0)
            {
                visible--;
                continue;
            }

            p1 = 0;
            p2 = 0;
            p3 = 0;
            p4 = 0;

            for(int p = i-1; p >= 0; p--)
            {
                if(books[p][j] >= books[i][j])
                {
                    p1 = true;
                    break;
                }
            }

            if(!p1) continue;

            for(int p = i+1; p < n; p++)
            {
                if(books[p][j] >= books[i][j])
                {
                    p2 = true;
                    break;
                }
            }

            if(!p2) continue;

            for(int p = j-1; p >= 0; p--)
            {
                if(books[i][p] >= books[i][j])
                {
                    p3 = true;
                    break;
                }
            }

            if(!p3) continue;

            for(int p = j+1; p < n; p++)
            {
                if(books[i][p] >= books[i][j])
                {
                    p4 = true;
                    break;
                }
            }

            if(!p4) continue;

            visible--;
        }
    }

    cout<<visible<<endl;
    return 0;
}
