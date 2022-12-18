#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int s[N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &s[i]), s[i] += s[i - 1];
    int l, r;
    while(m -- ) {
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}

// 前缀和
// https://www.acwing.com/problem/content/797/