#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxH = 55, maxW = 55;

int h, w, ans, matrix1[maxH][maxW], cs = 1;
char matrix[maxH][maxW];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        ans = 0;

        cin>>h>>w;
        if(h == 0 && w == 0) break;

        memset(matrix1, 0, sizeof(matrix1));

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                cin>>matrix[i][j];
            }
        }

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(matrix[i][j] == 'A') matrix1[i][j] = 1;
            }
        }
        for(int let = 1; let < 26; let++)
        {
            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    if(matrix[i][j] == (char)(let + 'A'))
                    {
                        if(i - 1 >= 0)
                        {
                            if(j - 1 >= 0 && matrix[i - 1][j - 1] == (char)(let - 1 + 'A')) matrix1[i][j] = matrix1[i - 1][j - 1] + 1;
                            if(matrix[i - 1][j] == (char)(let - 1 + 'A')) matrix1[i][j] = max(matrix1[i - 1][j] + 1, matrix1[i][j]);
                            if(j + 1 < w && matrix[i - 1][j + 1] == (char)(let - 1 + 'A')) matrix1[i][j] = max(matrix1[i - 1][j + 1] + 1, matrix1[i][j]);
                        }
                        if(j + 1 < w)
                        {
                            if(matrix[i][j + 1] == (char)(let - 1 + 'A')) matrix1[i][j] = max(matrix1[i][j + 1] + 1, matrix1[i][j]);
                            if(i + 1 < h && matrix[i + 1][j + 1] == (char)(let - 1 + 'A')) matrix1[i][j] = max(matrix1[i + 1][j + 1] + 1, matrix1[i][j]);
                        }
                        if(i + 1 < h)
                        {
                            if(matrix[i + 1][j] == (char)(let - 1 + 'A')) matrix1[i][j] = max(matrix1[i + 1][j] + 1, matrix1[i][j]);
                            if(j - 1 >= 0 && matrix[i + 1][j - 1] == (char)(let - 1 + 'A')) matrix1[i][j] = max(matrix1[i + 1][j - 1] + 1, matrix1[i][j]);
                        }
                        if(j - 1 >= 0)
                        {
                            if(matrix[i][j - 1] == (char)(let - 1 + 'A')) matrix1[i][j] = max(matrix1[i][j - 1] + 1, matrix1[i][j]);
                        }
                    }
                }
            }
        }

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(matrix1[i][j] > ans && matrix1[i][j] == matrix[i][j] - 'A' + 1) ans = matrix1[i][j];
            }
        }

        cout<<"Case "<<cs<<": "<<ans<<endl;
        cs++;
    }

    return 0;
}
