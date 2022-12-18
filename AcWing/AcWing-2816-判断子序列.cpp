#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N], b[N];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int j = 1; j <= m; j ++ ) cin >> b[j];
    int cnt = 0;
    for(int i = 1, j = 1; i <= n; i ++ ) {
        while(j <= m && a[i] != b[j]) j ++;
        if(j <= m && a[i] == b[j]) cnt ++, j ++;
        if(j > m) break;
    }
    if(cnt == n) cout << "Yes";
    else cout << "No";
    return 0;
}

// 判断子序列
// https://www.acwing.com/problem/content/2818/