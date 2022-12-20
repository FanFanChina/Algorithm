#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;

int main() {
   // 关闭iostream和stdio的同步，取消cin和cout的绑定
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> n;
   vector <LL> A(n);
   for (int i = 0; i < n; ++i) cin >> A[i];
   if (n == 1) {
      for (int i = 1; i <= 3; i ++ ) {
         cout << "1 1\n";
         cout << -A[0] << "\n";
      }
      return 0;
   }
   cout << "1 " << n << "\n";
   for (int i = 0; i + 1 < n; i ++ ) cout << -A[i] * n << " "; cout << "0\n";
   cout << "1 " << n - 1 << "\n";
   for (int i = 0; i + 1 < n; i ++ ) cout << A[i] * (n - 1) << " "; cout << "\n";
   cout << n << " " << n << "\n";
   cout << -A[n - 1] << "\n";
   return 0;
}