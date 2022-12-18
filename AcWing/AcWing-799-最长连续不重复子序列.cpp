#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], s[N];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    int res = 0;
    for(int i = 1, j = 1; i <= n; i ++ ) {
        s[a[i]] ++ ;
        while(s[a[i]] > 1) s[a[j]] --, j ++ ;
        res = max(res, i - j + 1);
    }
    printf("%d", res);
    return 0;
}

// 最长连续不重复子序列
// https://www.acwing.com/problem/content/801/