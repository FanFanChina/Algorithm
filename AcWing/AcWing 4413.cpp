#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, t, cnt = 0;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++ )
    {
        scanf("%d", &t);
        if(t + k <= 5) cnt ++ ;
    }
    printf("%d", cnt / 3);
    printf("\n"), system("pause");
    return 0;
}