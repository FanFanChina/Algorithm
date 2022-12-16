#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;
int f[N][N];
char str[N];

bool check(char a, char b)
{
    if((a == '[' && b == ']') || (a == '(' && b == ')')) return true;
    return false;
}

int main()
{
    scanf("%s", str);
    int n = strlen(str);
    for(int len = 2; len <= n; len ++ )
        for(int i = 0; i + len - 1 < n; i ++ )
        {
            int j = i + len - 1;
            if(check(str[i], str[j])) f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
            for(int k = i; k < j; k ++ ) f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
        }
    printf("%d", n - f[0][n - 1]);
    return 0;
}
