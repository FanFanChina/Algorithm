#include <iostream>
using namespace std;

int main()
{
    int a, n, res = 1;
    cin >> a >> n;
    while(n)
    {
        if(n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    cout << res;
    return 0;
}