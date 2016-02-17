/**
Ivo Karagyozov
Zimni 2013 C2 knight
*/
#include<iostream>
#include<cstdio>
using namespace std;

int board[4][5], br = 0;

struct point
{
    int x, y;
};
bool isPointIn(point p)
{
    if(p.x >= 0 && p.x <= 3 && p.y >= 0 && p.y <= 4)return true;
    return false;
}
void recurse(int i, int j, int num)
{
    if(num == 20)
    {
        board[i][j] = 20;
        for(int p=0; p<4; p++)
        {
            for(int k=0; k<5; k++)
            {
                printf("%d", board[p][k]);
                if(p==3 && k==4)printf("\n");
                else printf(" ");
            }
        }
        board[i][j] = 0;
        br++;
        return;
    }
    board[i][j] = num;
    point p1, p2, p3, p4, p5, p6, p7, p8;
    p1.x = i-2; p1.y = j-1;
    p2.x = i-2; p2.y = j+1;
    p3.x = i-1; p3.y = j+2;
    p4.x = i+1; p4.y = j+2;
    p5.x = i+2; p5.y = j-1;
    p6.x = i+2; p6.y = j+1;
    p7.x = i+1; p7.y = j-2;
    p8.x = i-1; p8.y = j-2;
    if(isPointIn(p1) && board[p1.x][p1.y] == 0)recurse(p1.x, p1.y, num+1);
    if(isPointIn(p2) && board[p2.x][p2.y] == 0)recurse(p2.x, p2.y, num+1);
    if(isPointIn(p3) && board[p3.x][p3.y] == 0)recurse(p3.x, p3.y, num+1);
    if(isPointIn(p4) && board[p4.x][p4.y] == 0)recurse(p4.x, p4.y, num+1);
    if(isPointIn(p5) && board[p5.x][p5.y] == 0)recurse(p5.x, p5.y, num+1);
    if(isPointIn(p6) && board[p6.x][p6.y] == 0)recurse(p6.x, p6.y, num+1);
    if(isPointIn(p7) && board[p7.x][p7.y] == 0)recurse(p7.x, p7.y, num+1);
    if(isPointIn(p8) && board[p8.x][p8.y] == 0)recurse(p8.x, p8.y, num+1);
    board[i][j] = 0;
    return;
}

int main()
{
    printf("164\n");
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            for(int p=0; p<4; p++)
            {
                for(int k=0; k<5; k++)
                {
                    board[p][k] = 0;
                }
            }
            recurse(i, j, 1);
        }
    }
    return 0;
}
