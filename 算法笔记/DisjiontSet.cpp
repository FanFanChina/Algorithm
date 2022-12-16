#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int id[N], n;

void init() {
    for(int i = 1; i <= n; i ++ ) id[i] = i;
}

void unition(int p, int q) {
    int pid = id[p];
    int qid = id[q];
    for(int i = 1; i <= n; i ++ )
        if(id[i] == pid) id[i] = qid;
}

bool find(int p, int q) {
    return id[p] == id[q];
}

int main() {
    

    return 0;
}