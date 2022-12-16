#include <cstdio>
#include <iostream>
using namespace std;

int n;

void dfs(int u, int state)
{
    if(u == n)
    {
        for(int i = 0; i < n; i ++ )
            if(state >> i & 1)
                printf("%d ", i + 1);
        printf("\n");
        return;
    }
    dfs(u + 1, state);
    dfs(u + 1, state | 1 << u);
}

int main()
{
    scanf("%d", &n);
    dfs(0, 0);
    printf("\n"), system("pause");
    return 0;
}