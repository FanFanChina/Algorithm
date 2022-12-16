#include <bits/stdc++.h>
using namespace std;
typedef vector <int> VI;

VI div(VI &A, int &b, int &r) {
    VI C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- ) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a;
    int b;
    cin >> a >> b;
    VI A;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    int r;
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
    printf("\n%d", r); 
    return 0;
}

// 高精度除法
// https://www.acwing.com/problem/content/796/
// 除法是从最高位开始，但因为我们还是倒叙导入，所以要逆序计算