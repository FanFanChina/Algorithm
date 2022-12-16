#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500;
int g[N][N];
bool st[N][N];
int n, m, x, y;
struct Node
{
    int x, y;
};
int dx[8] = { 2,-2,2,-2,-1,1,-1,1 };
int dy[8] = { 1,1,-1,-1,2,2,-2,-2 };

void bfs(int x, int y)
{
    queue <Node> q;
    q.push({x, y});
    g[x][y] = 0;
    st[x][y] = true;
    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i = 0; i < 8; i ++ )
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && !st[tx][ty])
            {
                q.push({tx, ty});
                g[tx][ty] = g[x][y] + 1;
                st[tx][ty] = true;
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    memset(g, -1, sizeof g);
    bfs(x, y);
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
            printf("%-5d", g[i][j]);
        printf("\n");
    }
    printf("\n"), system("pause");
    return 0;
}