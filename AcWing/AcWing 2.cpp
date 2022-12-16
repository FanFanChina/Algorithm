#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e3 + 10;

int f[N][N]; // 只考虑前i个物品，且体积不超过j
int w[N], v[N];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++) // 可以什么也不选，所以从0开始
        {
            if (j >= v[i])
                f[i][j] = f[i - 1][j - v[i]] + w[i];
            f[i][j] = max(f[i - 1][j], f[i][j]);
        }
    printf("%d\n", f[n][m]);
    printf("\n"), system("pause");
    return 0;
}

// 01 背包问题
// 状态：选或不选
// 如果选了，选后的体积j一定  >= v[i], 可以用来选前特判一下