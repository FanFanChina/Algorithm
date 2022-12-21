#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"

using namespace std;
typedef long long LL;

int n;

LL C(int n, int m) {
    LL res = 1;
    for(int i = n, j = 1; j <= m; j ++ , i -- ) res = res * i / j;
    return res;
}

bool check(int k) {
    int l = 2 * k, r = max(n, l); // n 一定会在n行及n行之前出现
    while(l < r) {
        int mid = l + r >> 1;
        if(C(mid, k) >= n) r = mid;
        else l = mid + 1;
    }
    if(C(r, k) != n) return false;
    cout << 1ll * (1 + r) * r / 2 + k + 1;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n;
    for(int i = 16; ; i --) 
        if(check(i)) break;
    return 0;
}

// 杨辉三角形
// https://www.acwing.com/problem/content/3421/
