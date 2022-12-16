#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], n, q;

int findStart(int k) {
    int l = 0, r = n + 1;
    while(l + 1 != r) {
        int mid = l + r >> 1;
        if(a[mid] >= k) r = mid;
        else l = mid;
    }
    if(a[r] == k) return r - 1;
    else return -1;
}

int findEnd(int k) {
    int l = 0, r = n + 1;
    while(l + 1 != r) {
        int mid = l + r >> 1;
        if(a[mid] <= k) l = mid;
        else r = mid;
    }
    if(a[l] == k) return l - 1;
    else return -1;
}


int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    int k;
    while(q -- ) {
        cin >> k;
        cout << findStart(k) << ' ' << findEnd(k) << endl;
    }
    return 0;
}