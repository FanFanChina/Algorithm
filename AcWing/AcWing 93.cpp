#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

void dfs(int s, int u, int state)
{
    if(u == k)
    {
        for(int i = 0; i < n; i ++ )
            if(state >> i & 1)
                printf("%d ", i + 1);
        printf("\n");
        return;
    }
    for(int i = s; i < n; i ++)
        dfs(i + 1, u + 1, state | 1 << i);
}

int main()
{
    scanf("%d%d", &n, &k);
    dfs(0, 0, 0);
    printf("\n"), system("pause");
    return 0;
}
