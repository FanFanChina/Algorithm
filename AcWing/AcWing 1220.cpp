#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
int n, w[N];
LL f[N], res;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int father)
{
    f[u] = w[u];
    for(int i = h[u]; ~i; i = ne[i])
    {
    int j = e[i];
	    if(j != father)
	    {
	        dfs(j, u);
	        f[u] += max(0ll, f[j]);
	    }
    }

}


int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    memset(h, -1, sizeof h);
    for(int i = 1; i < n; i ++ )
    {
    	int a, b;
	scanf("%d%d", &a, &b);
	add(a, b), add(b, a);
    }
    dfs(1, -1);
    res = f[1];
    for(int i = 2; i <= n; i ++ ) res = max(res, f[i]);
    printf("%lld", res);
    return 0;
}
