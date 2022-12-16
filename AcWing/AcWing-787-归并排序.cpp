#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], temp[N], n;

void mergeSort(int a[], int l, int r) {
    if(l >= r) return;
    int mid = l + r >> 1;
    mergeSort(a, l, mid), mergeSort(a, mid + 1, r);
    int k = 1, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) temp[k ++ ] = a[i ++ ];
        else temp[k ++ ] = a[j ++ ];
    }
    while(i <= mid) temp[k ++ ] = a[i ++ ];
    while(j <= r) temp[k ++ ] = a[j ++ ];
    for(int i = l, j = 1; i <= r; i ++, j ++ ) a[i] = temp[j];
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    mergeSort(a, 1, n);
    for(int i = 1; i <= n; i ++ ) printf("%d ", a[i]);
    return 0;
}

// 归并排序
// https://www.acwing.com/problem/content/789/
// 1. 确定边界点
// 2. 递归排序left and right
// 3. 归并合二为一