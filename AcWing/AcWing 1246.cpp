#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N], n;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int d = 0;
    for (int i = 2; i <= n; i++)
        d = gcd(d, a[i] - a[1]);
    if (d == 0)
        printf("%d", n);
    else
        printf("%d", (a[n] - a[1]) / d + 1);
    printf("\n"), system("pause");
    return 0;
}

// gcd (a 变 b、b 变 a % b)