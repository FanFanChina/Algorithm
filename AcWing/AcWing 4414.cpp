#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, t;
int minn = INT_MAX; // 最小正奇数
int maxn = INT_MIN; // 最大负奇数

int main()
{
    int sum = 0;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        if (t > 0)
            sum += t;
        if (t > 0 && t % 2 != 0)
            minn = min(minn, t);
        if (t < 0 && t % 2 != 0)
            maxn = max(maxn, t);
    }
    if (sum % 2 == 0)
        sum = max(sum - minn, sum + maxn);
    printf("%d", sum);
    printf("\n"), system("pause");
    return 0;
}

// 偶数和奇数奇数运算变奇数
// 符合的最大值有下列情况
// 所有正数加起来是奇数
// 所有正数加起来是偶数，那么就比较减去最小奇正数和加上最大奇负数哪个大
// 如果没有正数那么答案就是最大奇负数