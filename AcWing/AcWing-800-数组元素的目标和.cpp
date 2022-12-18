#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m, p;
int a[N], b[N];

int main() {
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= m; i ++ ) cin >> b[i];
    for(int i = 1, j = m; i <= n; i ++ ) {
        while(j >= 1 && a[i] + b[j] > p) j --;
        if(a[i] + b[j] == p) {
            printf("%d %d", i - 1, j - 1);
            break;
        }
    }
    return 0;
}

// 数组元素的目标和
// https://www.acwing.com/problem/content/802/