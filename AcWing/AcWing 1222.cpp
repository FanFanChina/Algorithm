#include <cstdio>
#include <cstring>
#include <iostream>
#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int f[N][N];  // 区间i到j内的回文子串的集合
char str[N];

int main()
{
    scanf("%s", str);
    int n = strlen(str);
    for(int len = 1; len <= n; len ++ )
    {
        for(int i = 0; i + len - 1 < n; i ++ )
        {
            int j = i + len - 1;
            if(len == 1) f[i][j] = 1;
            else
            {
                f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                if(str[i] == str[j]) 
                    f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
            }
        }
    }
    printf("%d\n", f[0][n - 1]);
    printf("\n"), system("pause");
    return 0;
}

// 密码脱落
// 区间DP模板
// 先枚举区间长度、在枚举区间左端点
