#include <bits/stdc++.h>
using namespace std;
typedef vector <int> VI;

// A >= B
bool cmp(VI &A, VI &B) {
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0; i -- ) 
        if(A[i] != B[i]) return A[i] > B[i];
    return true;
}

VI sub(VI &A, VI &B) {
    VI C;
    // t = 0 无进位 t = 1 有进位
    for(int i = 0, t = 0; i < A.size(); i ++ ) {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        // (t + 10) % 10 将两种情况合二为一
        C.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    // 消去前导0
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;
    VI A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');
    if(cmp(A, B)) {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
    } else {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
    }
    return 0;
}

// 高精度减法
// https://www.acwing.com/problem/content/794/
// 先要给 t 赋值
// (t + 10) % 10 将两种情况合二为一
// 结果有问题，倒着看