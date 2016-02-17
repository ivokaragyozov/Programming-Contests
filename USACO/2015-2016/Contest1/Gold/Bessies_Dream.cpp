#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1005, maxM = 1005;

struct node
{
    bool smell;
    int x, y, moves, lastMove;

    node(){}
    node(bool smell, int x, int y, int moves, int lastMove)
    {
        this->smell = smell;
        this->x = x;
        this->y = y;
        this->moves = moves;
        this->lastMove = lastMove;
    }
};

bool vis[maxN][maxM][6][2], k;
int n, m, board[maxN][maxM], ans;
queue<node> q;

void bfs()
{
    bool smell;
    int x, y, moves, currMove, lastMove;
    q.push(node(0, 0, 0, 0, 5));

    while(!q.empty())
    {
        smell = q.front().smell;
        x = q.front().x;
        y = q.front().y;
        moves = q.front().moves;
        lastMove = q.front().lastMove;
        q.pop();

        //cout<<x<<" "<<y<<" "<<smell<<" "<<moves<<" "<<lastMove<<endl;

        if(board[x][y] == 2) smell = true;

        if(x == n - 1 && y == m - 1)
        {
            k = true;
            ans = moves;
            break;
        }

        if(vis[x][y][lastMove][smell]) continue;
        vis[x][y][lastMove][smell] = true;

        if(x > 0 && board[x - 1][y] != 0)
        {
            if(board[x - 1][y] == 1 && !vis[x - 1][y][3][smell]) q.push(node(smell, x - 1, y, moves + 1, 3));
            else if(board[x - 1][y] == 2 && !vis[x - 1][y][3][1]) q.push(node(1, x - 1, y, moves + 1, 3));
            else if(board[x - 1][y] == 3 && smell && !vis[x - 1][y][3][1]) q.push(node(1, x - 1, y, moves + 1, 3));
            else if(board[x - 1][y] == 4 && !vis[x - 1][y][3][smell])
            {
                //vis[x - 1][y][3][0] = true;
                //vis[x - 1][y][3][1] = true;
                int moves1 = moves + 1, i;
                for(i = x; i >= 1; i--)
                {
                    if(board[i - 1][y] == 0 || board[i - 1][y] == 3)
                    {
                        i++;
                        moves1--;
                        break;
                    }
                    else if(board[i - 1][y] != 4)
                    {
                        break;
                    }
                    moves1++;
                }

                if(i == 0) i++, moves1--;
                q.push(node(0, i - 1, y, moves1, 3));
            }
        }
        if(y < m - 1 && board[x][y + 1] != 0)
        {
            if(board[x][y + 1] == 1 && !vis[x][y + 1][4][smell]) q.push(node(smell, x, y + 1, moves + 1, 4));
            else if(board[x][y + 1] == 2 && !vis[x][y + 1][4][1]) q.push(node(1, x, y + 1, moves + 1, 4));
            else if(board[x][y + 1] == 3 && smell && !vis[x][y + 1][4][1]) q.push(node(1, x, y + 1, moves + 1, 4));
            else if(board[x][y + 1] == 4 && !vis[x][y + 1][4][smell])
            {
                //vis[x][y + 1][4][0] = true;
                //vis[x][y + 1][4][1] = true;

                int moves1 = moves + 1, i;
                for(i = y; i < m - 1; i++)
                {
                    if(board[x][i + 1] == 0 || board[x][i + 1] == 3)
                    {
                        i--;
                        moves1--;
                        break;
                    }
                    else if(board[x][i + 1] != 4)
                    {
                        break;
                    }
                    moves1++;
                }

                //cout<<"x "<<i<<" "<<x<<endl;
                if(i == m - 1) i--, moves1--;
                q.push(node(0, x, i + 1, moves1, 4));
            }
        }
        if(x < n - 1 && board[x + 1][y] != 0)
        {
            if(board[x + 1][y] == 1 && !vis[x + 1][y][1][smell]) q.push(node(smell, x + 1, y, moves + 1, 1));
            else if(board[x + 1][y] == 2 && !vis[x + 1][y][1][1]) q.push(node(1, x + 1, y, moves + 1, 1));
            else if(board[x + 1][y] == 3 && smell && !vis[x + 1][y][1][1]) q.push(node(1, x + 1, y, moves + 1, 1));
            else if(board[x + 1][y] == 4 && !vis[x + 1][y][1][smell])
            {
                //vis[x + 1][y][1][0] = true;
                //vis[x + 1][y][1][1] = true;

                int moves1 = moves + 1, i;
                for(i = x; i < n - 1; i++)
                {
                    if(board[i + 1][y] == 0 || board[i + 1][y] == 3)
                    {
                        i--;
                        moves1--;
                        break;
                    }
                    else if(board[i + 1][y] != 4)
                    {
                        break;
                    }
                    moves1++;
                }

                //cout<<"x "<<x<<" "<<i + 1<<endl;
                if(i == n - 1) i--, moves1--;
                q.push(node(0, i + 1, y, moves1, 1));
            }
        }
        if(y > 0 && board[x][y - 1] != 0)
        {
            if(board[x][y - 1] == 1 && !vis[x][y - 1][2][smell]) q.push(node(smell, x, y - 1, moves + 1, 2));
            else if(board[x][y - 1] == 2 && !vis[x][y - 1][2][1]) q.push(node(1, x, y - 1, moves + 1, 2));
            else if(board[x][y - 1] == 3 && smell && !vis[x][y - 1][2][1]) q.push(node(1, x, y - 1, moves + 1, 2));
            else if(board[x][y - 1] == 4 && !vis[x][y - 1][2][smell])
            {
                //vis[x][y - 1][2][0] = true;
                //vis[x][y - 1][2][1] = true;

                int moves1 = moves + 1, i;
                for(i = y; i >= 1; i--)
                {
                    if(board[x][i - 1] == 0 || board[x][i - 1] == 3)
                    {
                        i++;
                        moves1--;
                        break;
                    }
                    else if(board[x][i - 1] != 4)
                    {
                        break;
                    }
                    moves1++;
                }

                if(i == 0) i++, moves1--;
                q.push(node(0, x, i - 1, moves1, 2));
            }
        }
    }
}

int main()
{
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>board[i][j];
        }
    }

    bfs();

    if(k) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
