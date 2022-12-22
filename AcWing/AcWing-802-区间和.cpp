#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
typedef vector <int> VI;

const int N = 3e5 + 10;
int n, m;
int a[N], s[N];
VI alls;
vector <PII> add, query;

// 寻找原值在离散化数组中的下标
int find(int x) {
    int l = -1, r = alls.size();
    while(l + 1 != r) {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid;
    }
    return r + 1;
}

int main() {
    cin >> n >> m;
    int x, c;
    for(int i = 1; i <= n; i ++ ) {
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    int l, r;
    for(int i = 1; i <= m; i ++ ) {
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l), alls.push_back(r);
    }
    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    // 处理添加
    for(auto it : add) {
        int x = find(it.first);
        a[x] += it.second;
    }
    // 预处理前缀和
    for(int i = 1; i <= alls.size(); i ++ ) s[i] = s[i - 1] + a[i];
    // 处理询问
    for(auto it : query) {
        int l = find(it.first), r = find(it.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}

// 区间和
// https://www.acwing.com/problem/content/804/ 