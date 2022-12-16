#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main()
{
    int n, q, k;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (q--)
    {
        cin >> k;
        int l = -1, r = n;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (a[mid] < k)
                l = mid;
            else
                r = mid;
        }
        if (a[r] == k)
            cout << r << ' ';
        else
            cout << -1 << ' ';
        r = n;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (a[mid] > k)
                r = mid;
            else
                l = mid;
        }
        if (a[l] == k)
            cout << l << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}