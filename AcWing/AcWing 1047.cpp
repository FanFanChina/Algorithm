#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int f[N][N]; // 只考虑前i个物品，且sum % k == j 的集合
int n, k, w[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++) // %k范围是 (0 —— k - 1)
            f[i][j] = max(f[i - 1][j], f[i - 1][((j - w[i]) % k + k) % k] + w[i]);
    cout << f[n][0];
    printf("\n"), system("pause");
    return 0;
}
// 糖果
// 选择模型
// 状态划分：A —— 不选第j个物品 ｜ B —— 选第j个物品
// 状态表示：A —— f[i - 1][j] | B —— f[i - 1][((j - w[i]) % k + k) % k]
// 取模转化：加k模k
// memset 是按字节赋值的不可和INT_MIN连用