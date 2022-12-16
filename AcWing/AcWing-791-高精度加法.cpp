#include <bits/stdc++.h>
using namespace std;
typedef vector <int> VI;

VI add(VI &A, VI &B) {
    VI C;
    int t = 0;
    for(int i = 0; i < A.size() || i < B.size(); i ++ ) {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1); // 有数位扩充时，加上1 (也只可能是1)
    return C;
}

int main() {
    string a, b;
    VI A, B;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');
    auto C = add(A, B);
    for(int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
    return 0;
}

// 高精度加法
// https://www.acwing.com/problem/content/793/
// 注意字符串转化为数字时要减去 '0'