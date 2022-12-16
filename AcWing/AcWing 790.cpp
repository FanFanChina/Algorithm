#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    double n;
    scanf("%lf", &n);
    double l = -1000, r = 1000;
    while (r - l > 1e-8) // 10的-8次方
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid < n)
            l = mid;
        else
            r = mid;
    }
    printf("%.6lf", l);
    return 0;
}