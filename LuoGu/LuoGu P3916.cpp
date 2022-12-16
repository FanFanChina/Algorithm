#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int head[N], cnt;
struct Edge
{
    int to, next;
}e[N];
int n, m, maxn[N];

void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int v, int u)
{
    if(maxn[u]) return;
    maxn[u] = v;
    for(int i = head[u]; i; i = e[i].next) 
        dfs(v, e[i].to);
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    while(m -- )
    {
        scanf("%d%d", &u, &v);
        add(v, u);
    }
    for(int i = n; i >= 1; i -- ) dfs(i, i);
    for(int i = 1; i <= n; i ++ ) printf("%d ", maxn[i]);
    printf("\n"), system("pause");
    return 0;
}