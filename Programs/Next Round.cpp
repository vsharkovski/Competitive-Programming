#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int cnt = 0, treshold = max(a[k-1], 1);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= treshold)
        {
            ++cnt;
        }
        else
        {
            break;
        }
    }
    cout << cnt;
}
