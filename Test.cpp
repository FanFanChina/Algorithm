#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"

using namespace std;
typedef long long LL;

LL C(int n, int m) {
   LL res = 1;
   for(int i = n, j = 1; j <= m; i -- , j ++ ) res = res * i / j;
   return res;
}

int main() {
   ios_base::sync_with_stdio(false);cin.tie(nullptr);
   int n, m;
   cin >> n >> m;
   cout << C(n, m) << endl;
   return 0;
}