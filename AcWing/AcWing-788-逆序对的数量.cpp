#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;
int a[N], temp[N], n;

LL mergeSort(int l, int r) {
    if(l >= r) return 0;
    int mid = l + r >> 1;
    LL res = mergeSort(l, mid) + mergeSort(mid + 1, r);
    int k = 1, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) temp[k ++ ] = a[i ++ ];
        else {
            temp[k ++ ] = a[j ++ ];
            // 计算当前相对于a[j]的逆序对的个数
            res += mid - i + 1;
        }
    }
    while(i <= mid) temp[k ++ ] = a[i ++ ];
    while(j <= r) temp[k ++ ] = a[j ++ ];
    for(int i = l, j = 1; i <= r; i ++ , j ++ ) a[i] = temp[j];
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    printf("%lld", mergeSort(1, n));
    return 0;
}

// 逆序对的数量
// https://www.acwing.com/problem/content/790/
// 对于全部倒序的情况，逆序对最多，为n方/2，因为n可能为1e5会爆int，所以要用long long
// 对于a[i] > a[j]时，a[i - mid] 均大于a[j], 对于a[j]而言，与其构成逆序对的个数为mid - i + 1