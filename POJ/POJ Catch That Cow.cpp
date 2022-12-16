#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int a, b, tim[N];
bool st[N];

void bfs()
{
    // 初始化
    tim[a] = 0;
    st[a] = true;
    queue <int> q;
    q.push(a);
    //开始往下宽搜
    while(!q.empty())
    {
        int p = q.front(); q.pop(); 
        if(p == b)
        {
            printf("%d", tim[b]);
            return;
        }
        int x;
        x = p + 1;
        if (x >= 0 && x <= 100000 && !st[x])
        {
            q.push(x);
            st[x] = true;
            tim[x] = tim[p] + 1;
        }
        x = p - 1;
        if (x >= 0 && x <= 100000 && !st[x])
        {
            q.push(x);
            st[x] = true;
            tim[x] = tim[p] + 1;
        }
        x = p * 2;
        if (x >= 0 && x <= 100000 && !st[x])
        {
            q.push(x);
            st[x] = true;
            tim[x] = tim[p] + 1;
        }
    }
}

int main()
{
    scanf("%d%d", &a, &b);
    bfs();
    printf("\n"), system("pause");
    return 0;
}

// 常规队列头是front
// BFS模板：初始化、取、出、判断、入