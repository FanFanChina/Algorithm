#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;

int T, n, k;

VI solve(int n) {
    // n is odd.
    if(n % 2 == 1) return {1, n / 2, n / 2};
    // n is even and is a multiple of 4.
    if(n % 4 == 0) return {n / 2, n / 4, n / 4};
    // n is even and is not a multiple of 4.
    if(n % 2 == 0) return {n / 2 - 1, n / 2 - 1, 2};
}

int main() {
    cin >> T;
    while(T -- ) {
        cin >> n >> k;
        auto ans = solve(n);
        for(auto it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}

// k-LCM (easy version)
// https://codeforces.com/contest/1497/problem/C1