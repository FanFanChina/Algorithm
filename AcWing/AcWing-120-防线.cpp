#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"

using namespace std;
typedef long long LL;
const int N = 2e5 + 10;

struct Seg {
    int s, e, d;
}segs[N];
int T, n;

LL getSum(int x) {
    LL res = 0;
    for(int i = 1; i <= n; i ++ ) {
        if(segs[i].s <= x) 
            res += (min(x, segs[i].e) - segs[i].s) / segs[i].d + 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> T;
    while(T -- ) {
        cin >> n;
        LL l = -1, r = 0;
        for(int i = 1; i <= n; i ++ ) {
            int s, e, d;
            cin >> s >> e >> d;
            segs[i] = {s, e, d};
            r = max(r, 1ll * e);
        }
        r ++;
        while(l + 1 != r) {
            int mid = l + r >> 1;
            if(getSum(mid) & 1) r = mid;
            else l = mid;
        }
        auto sum = getSum(r) - getSum(r - 1);
        if(sum % 2) cout << r << ' ' << sum << endl;
        else cout << "There's no weakness." << endl;
    }
    return 0;
}

// 防线
// https://www.acwing.com/problem/content/122/