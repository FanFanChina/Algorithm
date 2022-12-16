#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 25, M = 1e8 + 10;
int a[N], n, k, ans;
int primes[M], cnt;
bool st[M];

void getPrimes(int k)
{
    for(int i = 2; i <= k; i ++ )
    {
        if(!st[i]) primes[cnt ++ ] = i;
        for(int j = 0; primes[j] * i <= k; j ++ )
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void dfs(int s, int u, int state)
{
    if(u == k)
    {
        int t = 0;
        for(int i = 0; i < n; i ++)
            if(state >> i & 1) t += a[i];
        if(!st[t]) ans ++ ;
    }
    for(int i = s; i < n; i ++ )
        dfs(i + 1, u + 1, state | 1 << i);
}

int main()
{
    getPrimes(M);
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    dfs(0, 0 ,0);
    printf("%d", ans);
    printf("\n"), system("pause");
    return 0;
}

// 选数
// 组合枚举
// 素数线性筛法