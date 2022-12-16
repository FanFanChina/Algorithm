#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int a, b, tim[N];
bool st[N];

void bfs()
{
    // ��ʼ��
    tim[a] = 0;
    st[a] = true;
    queue <int> q;
    q.push(a);
    //��ʼ���¿���
    while(!q.empty())
    {
        int p = q.front(); q.pop(); 
        if(p == b)
        {
            printf("%d", tim[b]);
            return;
        }
        int x;
        x = p + 1;
        if (x >= 0 && x <= 100000 && !st[x])
        {
            q.push(x);
            st[x] = true;
            tim[x] = tim[p] + 1;
        }
        x = p - 1;
        if (x >= 0 && x <= 100000 && !st[x])
        {
            q.push(x);
            st[x] = true;
            tim[x] = tim[p] + 1;
        }
        x = p * 2;
        if (x >= 0 && x <= 100000 && !st[x])
        {
            q.push(x);
            st[x] = true;
            tim[x] = tim[p] + 1;
        }
    }
}

int main()
{
    scanf("%d%d", &a, &b);
    bfs();
    printf("\n"), system("pause");
    return 0;
}

// �������ͷ��front
// BFSģ�壺��ʼ����ȡ�������жϡ���