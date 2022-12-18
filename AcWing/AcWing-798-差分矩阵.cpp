#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int b[N][N];
int n, m, q;

void modify(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main() {
    cin >> n >> m >> q;
    int t;
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= m; j ++ ) {
            cin >> t;
            modify(i, j, i, j, t);
        }
    int x1, y1, x2, y2, v;
    while(q -- ) {
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        modify(x1, y1, x2, y2, v);
    }   
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// 差分矩阵
// https://www.acwing.com/problem/content/description/800/