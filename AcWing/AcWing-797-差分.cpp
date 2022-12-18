#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int c[N], n, m;

void modify(int l, int r, int v) {
    c[l] += v;
    c[r + 1] -= v;
}


int main() {
    cin >> n >> m;
    int t;
    for(int i = 1; i <= n; i ++ ) scanf("%d", &t), modify(i, i, t);
    int l, r, v;
    while(m -- ) {
        cin >> l >> r >> v;
        modify(l, r, v);
    }
    for(int i = 1; i <= n; i ++ ) c[i] += c[i - 1], printf("%d ", c[i]);
    return 0;
}

// 差分
// https://www.acwing.com/problem/content/799/