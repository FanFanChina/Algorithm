#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl "\n"

using namespace std;
const int N = 1e5 + 10;

// head : 头节点下标
// e[i] : i 号节点的val
// ne[i] : i 的下一个节点的下标
// idx : 存储当前用到了哪个点

int head, e[N], ne[N], idx, m;

// 初始化链表
void init() {
    head = -1;
    idx = 0;
}

// 将x插到头节点
void addToHead(int x) {
    e[idx] = x, ne[idx] = head, head = idx ++;
}

// 将x插到第k个插入的节点后面
void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
}

// 删除下标为k的后面那个点删掉
void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    init();
    cin >> m;
    char op;
    int k, x;
    while(m -- ) {
        cin >> op;
        if(op == 'H') {
            cin >> x;
            addToHead(x);
        } else if(op == 'D') {
            cin >> k;
            if(k == 0) head = ne[head];
            else remove(k - 1);   // 因为题目中下标从1开始, 所以要减去一
        } else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for(int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    return 0;
}

// 单链表
// https://www.acwing.com/problem/content/828/