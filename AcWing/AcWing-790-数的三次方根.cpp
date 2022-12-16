#include <bits/stdc++.h>
using namespace std;

double n;

int main() {
    scanf("%lf", &n);
    double l = -1000, r = 1000;
    while(r - l > 1e-8) {
        double mid = (l + r) / 2;
        if(mid * mid * mid < n) l = mid;
        else r = mid;
    }
    printf("%.6lf", l)
    return 0;
}

// 数的三次方根
// https://www.acwing.com/problem/content/792/
// 注意是 r - l > 1e-8 时才进行循环