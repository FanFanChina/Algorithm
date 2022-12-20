#include <bits/stdc++.h>
using namespace std;

#define endl "\n"         // 优化 endl
#pragma GCC optimize(3)   // 开启 O3 优化

typedef long long LL;
int n;
 
int main() {
    // 关闭iostream和stdio的同步，取消cin和cout的绑定
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    vector <LL> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    if(n == 1) {
        for(int i = 1; i <= 3; i ++ ) {
            cout << "1 1" << endl;
            cout << -a[0] << endl;
            a[0] = 0;
        }
    } else {
        // One
        cout << "1 1" << endl;
        cout << -a[0] << endl;
        // Two
        cout << "1 " << n << endl;
        for(int i = 0; i < n; i ++ ) {
            if(i == 0) cout << "0 ";
            else cout << -1 * n * a[i] << ' ';
        }
        cout << endl;
        // Three
        cout << "2 " << n << endl;
        for(int i = 1; i < n; i ++ ) cout << (n - 1) * a[i] << ' ';
        cout << endl;
    }
    return 0;
}

// Multiples of Length
// https://codeforces.com/contest/1396/problem/A