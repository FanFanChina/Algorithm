#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    cin >> t;
    while(t -- ) {
        cin >> n;
        if(n < 4) {
            cout << "-1" << endl;
            continue;
        }
        for(int i = n; i >= 1; i -- ) {
            if(i & 1) cout << i << ' ';
        }
        cout << '4' << ' ' << '2' << ' ';
        for(int i = 6; i <= n; i += 2) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// Special Permutation
// https://codeforces.com/problemset/problem/1352/G