#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"
#define ff first
#define ss second

using namespace std;
typedef pair <int, int> PII;
typedef vector <int> VI;
const int N = 1010;
vector <PII> points;
VI alls;
int C, n;
int s[N][N];

int find(int x) {
    int l = -1, r = alls.size();
    while(l + 1 != r) {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid;
    }
    return r;
}

bool check(int len) {
    for(int x1 = 0, x2 = 1; x2 < alls.size(); x2 ++ ) {
        while(alls[x2] - alls[x1 + 1] + 1 > len) x1 ++;
        for(int y1 = 0, y2 = 1; y2 < alls.size(); y2 ++ ) {
            while(alls[y2] - alls[y1 + 1] + 1 > len) y1 ++ ;
            if(s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] >= C) return true;
        } 
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> C >> n;
    int x, y;
    alls.push_back(0);
    for(int i = 1; i <= n; i ++ ) {
        cin >> x >> y;
        points.push_back({x, y});
        alls.push_back(x), alls.push_back(y);
    }
    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    // 初始化地图
    for(auto it : points) {
        int x = find(it.ff), y = find(it.ss);
        s[x][y] ++;
    }
    // 前缀和
    for(int i = 1; i <= alls.size(); i ++ )
        for(int j = 1; j <= alls.size(); j ++ ) 
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    int l = 0, r = 10001;
    while(l + 1 != r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}

// 赶牛入圈
// https://www.acwing.com/problem/content/123/