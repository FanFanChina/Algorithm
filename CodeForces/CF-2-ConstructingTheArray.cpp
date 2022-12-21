#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;

int t, n;

struct cmp {
	bool operator() (const PII &a, const PII &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};

int main() {
    cin >> t;
    while(t -- ) {
        cin >> n;
        set <PII, cmp> segs;
        segs.insert({0, n - 1});
        vector <int> a(n);
        for(int i = 1; i <= n; i ++ ) {
            // 遍历 segs
            // for(auto it : segs) {
            //     cout << "[" << it.first << ", " << it.second << "]" << ' ';
            // }
            // cout << endl;
            PII cur = *segs.begin();
            segs.erase(segs.begin());
            int id = (cur.first + cur.second) / 2;
            a[id] = i;
            // id 左边还有数
            if(cur.first < id) segs.insert({cur.first, id - 1});
            // id 右边还有数
            if(id < cur.second) segs.insert({id + 1, cur.second});
        }
        for (auto it : a) cout << it << ' ';
        cout << endl;
    }
    return 0;
}

// Constructing the Array
// https://codeforces.com/problemset/problem/1353/D