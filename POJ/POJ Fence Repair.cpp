#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
priority_queue < int, vector <int>, greater <int> > q;

int main()
{
    int n, temp;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++ ) scanf("%d", &temp), q.push(temp);
    if(q.size() == 1) 
        cout << temp;
    else
    {
        LL sum = 0;
        while(q.size() != 1)
        {
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            sum += a + b; q.push(a + b);
        }
        printf("%lld", sum);
    } 
    // printf("\n"), system("pause");
    return 0;
}

// priority_queue <int, vector <int>, greater <int> >
// 取 2 入 1， sum 求和
// 特判 + 为一输出