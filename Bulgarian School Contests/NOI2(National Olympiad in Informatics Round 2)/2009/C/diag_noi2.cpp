/**
Ivo Karagyozov
NOI2 2009 C3 diag
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, p, board[105][105], number[105][105], brnums=0, maxnum=0;
vector<int> nums;

int main()
{
    scanf("%d%d", &n, &p);
    int num=1;
    for(int j=0; j<n; j++)
    {
        int i1=0, j1=j;
        while(i1>=0 && j1>=0 && i1<n && j1<n)
        {
            number[i1][j1]=num++;
            i1++;
            j1--;
        }
    }
    for(int i=1; i<n; i++)
    {
        int i1=i, j1=n-1;
        while(i1>=0 && j1>=0 && i1<n && j1<n)
        {
            number[i1][j1]=num++;
            i1++;
            j1--;
        }
    }
    brnums=(n*n*p)/100;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &board[i][j]);
            nums.push_back(board[i][j]);
        }
    }
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            bool p=false;
            int sum=0;
            for(int k=brnums-1; k>=0; k--)
            {
                if(nums[k]>board[i][j])
                {
                    p=true;
                    break;
                }
            }
            if(p==false && maxnum<number[i][j])maxnum=number[i][j];
        }
    }
    printf("%d\n", maxnum);
    return 0;
}
