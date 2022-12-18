#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i ++ )
typedef long long LL;

const int N = 3e5 + 10;
int n;
LL a[N], b[N];

void solve() {
	scanf("%d", &n);
	forn(i, n) scanf("%lld%lld", &a[i], &b[i]);
	LL ans = 0, mn = 1e18;
	forn(i, n) {
		int next_i = (i + 1) % n;
		LL t = a[next_i] - b[i];
		if(t >= 0) ans += t;
		mn = min(mn, a[next_i] - b[i] >= 0 ? b[i] : a[next_i]);
	}
	printf("%lld\n", ans + mn);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T -- ) solve();
	return 0;
}

// Circle of Monsters
// https://codeforces.com/problemset/problem/1334/C