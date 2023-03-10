#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"

using namespace std;
const int N = 1e5 + 10;
int m;
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 0;
}

void addToHead(int x) {
    e[idx] = x, ne[idx] = head, head = idx ++;
}

void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    init();
    cin >> m;
    while(m -- ) {
        char op;
        int k, x;
        cin >> op;
        if(op == 'H') {
            cin >> x;
            addToHead(x);
        } else if(op == 'D') {
            cin >> k;
            if(!k) head = ne[head];
            else remove(k - 1);
        } else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for(int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    return 0;
}