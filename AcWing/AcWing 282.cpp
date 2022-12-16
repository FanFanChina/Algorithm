#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 310;
int n, a[N];
int f[N][N];
int s[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    memset(f, 0x3f, sizeof f);
    for (int len = 1; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if (len == 1)
            {
                f[i][j] = 0;
                continue;
            }
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
        }
    cout << f[1][n];
    return 0;
}