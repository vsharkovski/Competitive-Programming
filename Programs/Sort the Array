#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+n);
    int starti = 0, endi = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            starti = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; --i)
    {
        if (a[i] != b[i])
        {
            endi = i;
            break;
        }
    }
    bool ok = 1;
    for (int i = starti, j = endi; i <= endi && j >= 0; ++i, --j)
    {
        if (a[i] != b[j])
        {
            ok = 0;
            cout << "no";
            break;
        }
    }
    if (ok)
    {
        cout << "yes\n" << starti+1 << " " << endi+1;
    }
}
