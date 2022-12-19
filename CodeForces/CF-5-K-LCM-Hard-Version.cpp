#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;

int T, n, k;

VI solve(int n) {
    if(n % 2 == 1) return {1, n / 2, n / 2};
    if(n % 4 == 0) return {n / 2, n / 4, n / 4};
    if(n % 2 == 0) return {n / 2 - 1, n / 2 - 1, 2};
}

int main() {
    cin >> T;
    while(T -- ) {
        cin >> n >> k;
        auto ans = solve(n - (k - 3)); // 给第 3 - (k - 1) 个 1 留出值域
        for(int i = 0; i < k; i ++ ) cout << (i <= 2 ? ans[i] : 1) << ' ';
        cout << endl;
    }
    return 0;
}

// k-LCM (hard version)
// https://codeforces.com/problemset/problem/1497/C2