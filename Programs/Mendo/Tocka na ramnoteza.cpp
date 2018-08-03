#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;

    int remaining = 0;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        remaining += a[i];
    }

    int progress = 0, result = -1;
    for (int i = 0; i < n; ++i)
    {
        remaining -= a[i];
        if (progress == remaining)
        {
            result = i+1;
            break;
        }
        progress += a[i];
    }
    cout << result;
}
