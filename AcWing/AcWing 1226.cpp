#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 105, M = 10010;
int n, a[N];
bool f[N][M];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    scanf("%d", &n);
    int d = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        d = gcd(d, a[i]);
    }
    if (d != 1) printf("INF");
    else
    {
        memset(f, 0, sizeof f);
        f[0][0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= M; j++)
                f[i][j] = f[i - 1][j] || (j >= a[i] ? f[i][j - a[i]] : false);
        int ans = 0;
        for (int j = 0; j <= M; j ++ )
            if (!f[n][j]) ans++;
        printf("%d", ans);
    }
    return 0;
}