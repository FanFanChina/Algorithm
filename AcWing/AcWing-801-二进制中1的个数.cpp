#include <bits/stdc++.h>
using namespace std;

int n, t;

int lowBit(int x) {
    return x & -x;
}

int main() {
    scanf("%d", &n);
    while(n -- ) {
        scanf("%d", &t);
        int cnt = 0;
        while(t) {
            t -= lowBit(t);
            cnt ++;
        }
        printf("%d ", cnt);
    }
    return 0;
}

// 二进制中1的个数
// https://www.acwing.com/problem/content/803/