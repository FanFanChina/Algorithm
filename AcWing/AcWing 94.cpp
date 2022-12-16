#include <cstdio>
#include <iostream>
using namespace std;

const int N = 25;
int a[N], n;

void dfs(int u, int state)
{
    if(u == n)
    {
        for(int i = 0; i < n; i ++ )
            if(state >> i & 1)
                printf("%d ", a[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i ++ )
        if(!(state >> i & 1))
        {
            a[u] = i + 1;
            dfs(u + 1, state | 1 << i);
        }   
}

int main()
{
    scanf("%d", &n);
    dfs(0, 0);
    printf("\n"), system("pause");
    return 0;
}
