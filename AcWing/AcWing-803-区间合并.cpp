#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct Range{
    int l, r;
    bool operator < (const Range W) const {
        return l < W.l;
    }
}range[N];
int n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++ ) scanf("%d%d", &range[i].l, &range[i].r);
    sort(range + 1, range + 1 + n);
    int start = range[1].l, end = range[1].r, cnt = n;
    for(int i = 2; i <= n; i ++ ) {
        if(range[i].r <= end) cnt --;
        if(range[i].l <= end && range[i].r > end) cnt -- , end = range[i].r;
        if(range[i].l > end) start = range[i].l, end = range[i].r; 
    }
    cout << cnt;
    return 0;
}

// 区间合并
// https://www.acwing.com/problem/content/805/