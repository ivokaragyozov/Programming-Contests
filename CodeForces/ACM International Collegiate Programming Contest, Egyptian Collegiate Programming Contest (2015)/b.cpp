#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxQ = 105;

char a, b;
int t, q, m, questions[maxQ][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>q>>m;

        memset(questions, -1, sizeof(questions));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < q; j++)
            {
                cin>>a>>b;

                if(b == 'T') questions[j][a - 'A'] = 1;
                else questions[j][a - 'A'] = 0;
            }
        }


        for(int i = 0; i < q; i++)
        {
            int cnt = 0, ind = -1;
            for(int j = 0; j < 4; j++)
            {
                if(questions[i][j] == -1)
                {
                    cnt++;
                    ind = j;
                }
                else if(questions[i][j] == 1)
                {
                    cnt = 1;
                    ind = j;
                    break;
                }
            }

            if(cnt == 1) cout<<(char)(ind + 'A');
            else cout<<'?';

            if(i == q - 1) cout<<endl;
            else cout<<" ";
        }
    }

    return 0;
}
